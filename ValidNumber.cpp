//
// Created by soumya on 12/18/17.
//
#include <vector>
#include <zconf.h>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class ValidNumber {
public:
    struct state;
    typedef struct trans {
        state &toState;
        unordered_set<char> characters;
        trans( state &st, unordered_set<char> cond):
                toState(st), characters(cond){
        };
        trans(const trans& other):toState(other.toState),characters(other.characters)
        {
        };
        trans& operator=(const trans& other)
        {
            toState = other.toState ;
            characters = other.characters;
        }

    } TransCond;

    typedef struct state {
        state(const string &name) : name(name) {}

        std::string name;
        vector<TransCond> trans;

        bool operator==(struct state b) { return (name == b.name); };
        bool operator!=(struct state b) { return (name != b.name); };

    } State;


    State init, numeric, numeric2, dec, exp, err, eos,sign;

    ValidNumber() : init{"init"}, numeric{"numeric"}, numeric2{"numeric2"}, dec{"dec"}, exp{"exp"}, err{"err"},
                    eos{"eos"},sign{"sign"}

    {

        init.trans.push_back(TransCond {init, {' '}});
        init.trans.push_back(TransCond {sign, {'-', '+'}});
        init.trans.push_back(TransCond {numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        init.trans.push_back(TransCond {err, {}});

        sign.trans.push_back(TransCond{numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        sign.trans.push_back(TransCond {err, {}});


        numeric.trans.push_back(TransCond{exp, {'e'}});
        numeric.trans.push_back(TransCond{dec, {'.'}});
        numeric.trans.push_back(TransCond{eos, {' '}});
        numeric.trans.push_back(TransCond {err, {}});

        exp.trans.push_back(TransCond {numeric, {'0',
                                                 '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        exp.trans.push_back(TransCond {sign, { '-', '+'}});

        exp.trans.push_back(TransCond {err, {}});

        dec.trans.push_back(TransCond {numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        dec.trans.push_back(TransCond {err, {}});
        eos.trans.push_back(TransCond {eos, {' '}});
        eos.trans.push_back(TransCond {err, {}});
    }

    bool isNumber(string sin) {
        State state = init;

        State next_state = init;
        for (auto a: sin) {

            if (next_state==err) return false;
            state = next_state; next_state = err;
            auto transition = state.trans.begin();
            for (; transition !=  state.trans.end(); transition++) {

                auto found = transition->characters.find(a);

                if (found == transition->characters.end())
                    continue;

                next_state = transition->toState;
                break;
            }
        }
        if(next_state != eos || next_state != numeric2) return false;
    }
};
int main ()
{
    ValidNumber v;
   std::cout << v.isNumber("-1234.1e");
}