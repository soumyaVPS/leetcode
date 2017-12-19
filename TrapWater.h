//
// Created by soumya on 12/4/17.
//

#ifndef ADDTWONUMBERS_TRAPWATER_H
#define ADDTWONUMBERS_TRAPWATER_H

#include <vector>
using namespace std;
class TrapWater {
public:
    int trap(vector<int>& height);
private:
    /*void find_bounds(__gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &iterator,
                     __gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &normal_iterator, vector <int> & heights);

    int process_bounds(stack<tuple<long, int>> &, tuple<long, int>);
     */
    void find_bounds(__gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &lower,
                     __gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &upper, vector<int> &heights);

    int process_bounds(__gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> lower,
                       __gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> upper);
};


#endif //ADDTWONUMBERS_TRAPWATER_H
