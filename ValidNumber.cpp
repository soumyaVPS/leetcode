#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class ValidNumber {
public:
    struct state;
    typedef struct trans {
        state *toState;
        unordered_set<char> characters;
        trans( state &st, unordered_set<char> cond):
                toState(&st), characters(cond){
        };
        trans(const trans& other):toState(other.toState),characters(other.characters)
        {
        };
        trans& operator=(const trans& other)
        {
            toState = other.toState ;
            characters = other.characters;
            return *this;
        }

    } TransCond;

    typedef struct state {
        state(const string &name) : name(name) {}

        std::string name;
        vector<TransCond> trans;

        bool operator==(struct state b) { return (name == b.name); };
        bool operator!=(struct state b) { return (name != b.name); };

    } State;


    State init, numeric, dec,numeric2, exp, err, eos,sign;

    ValidNumber() : init{"init"}, numeric{"numeric"}, dec{"dec"}, exp{"exp"}, err{"err"},
                 eos{"eos"},sign{"sign"},numeric2{"numeric2"}

    {

        init.trans.push_back(TransCond {init, {' '}});
        init.trans.push_back(TransCond {sign, {'-','+'}});
        init.trans.push_back(TransCond {numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        init.trans.push_back(TransCond {err, {}});
        init.trans.push_back(TransCond{dec, {'.'}});

        sign.trans.push_back(TransCond{numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        sign.trans.push_back(TransCond{dec, {'.'}});

        numeric.trans.push_back(TransCond {numeric, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        numeric.trans.push_back(TransCond{exp, {'e'}});
        numeric.trans.push_back(TransCond{dec, {'.'}});
        numeric.trans.push_back(TransCond{eos, {' '}});
        numeric.trans.push_back(TransCond {err, {}});

        numeric2.trans.push_back(TransCond {numeric2, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        numeric2.trans.push_back(TransCond{exp, {'e'}});
        numeric2.trans.push_back(TransCond{eos, {' '}});
        numeric2.trans.push_back(TransCond {err, {}});

        exp.trans.push_back(TransCond {numeric2, {'0',
                                                  '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        exp.trans.push_back(TransCond {sign, { '-','+'}});

        exp.trans.push_back(TransCond {err, {}});

        dec.trans.push_back(TransCond {numeric2, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}});
        dec.trans.push_back(TransCond {eos, {' '}});
        dec.trans.push_back(TransCond{exp, {'e'}});
        dec.trans.push_back(TransCond {err, {}});

        eos.trans.push_back(TransCond {eos, {' '}});
        eos.trans.push_back(TransCond {err, {}});
    }

    bool isNumber(string sin) {

        size_t startpos = sin.find_first_not_of(" \t");
        if( std::string::npos != startpos )
        {
            sin = sin.substr( startpos );
        }

        size_t endpos = sin.find_last_not_of(" \t");
        if( std::string::npos != endpos )
        {
            sin = sin.substr( 0,endpos+1 );
        }
        bool founddig = false;
        bool foundexp = false;
        State *state = &init;

        State *next_state = &err;
        for (auto a: sin) {


            auto transition = state->trans.begin();
            for (; transition !=  state->trans.end(); transition++) {

                auto found = transition->characters.find(a);

                if (found == transition->characters.end())
                    continue;

                next_state = transition->toState;
                if (*next_state == numeric || *next_state == numeric2)
                {
                    founddig = true;
                }
                if (*next_state == exp && (!founddig || foundexp)) return false;
                else if(*next_state == exp)
                {founddig = false; foundexp = true;}
                break;
            }
            if (*next_state==err) return false;
            state = next_state; next_state = &err;
        }
        if(*state == eos ||
           *state == numeric || (*state ==dec && founddig) || *state == numeric2 ){
            return true;
        }
        return false;
    }

};