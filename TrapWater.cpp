//
// Created by soumya on 12/4/17.
//

#include <stack>
#include <tuple>
#include "TrapWater.h"
void TrapWater::find_bounds(__gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &lower,
                            __gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> &upper, vector <int> & heights) {
    auto highestupper = upper; int hval = *upper;
    while (highestupper != heights.end() && *highestupper < *lower)
    {
        highestupper++;
        if (hval < *highestupper)
        {
            upper = highestupper;
            hval = *highestupper;
        }
    }


}

int TrapWater::process_bounds(__gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> lower,
                              __gnu_cxx::__normal_iterator<vector<int>::pointer, vector<int>> upper) {
    int vol = 0;
    int maxval = *lower;
    if (*upper < *lower) maxval = *upper;
    while (lower!=upper)
    {
        if (maxval>*lower)
        {
            vol += (maxval-*lower);
        }
        lower++ ;
    }
    return vol;
}
int TrapWater::trap(vector<int>& heights)
{
    auto upper = heights.begin(); auto lower = heights.begin();
    int volume =0;
    while(upper!=heights.end() && lower!=heights.end())
    {
        upper++;
        find_bounds(lower,upper, heights);
        volume+= process_bounds(lower, upper);
        lower = upper;
    }
    return volume;
}

/*
static int vol =0;
int TrapWater::trap(vector<int>& heights)
{

    std::stack<tuple<long,int>> bounds;
    auto hiter = heights.begin();
    int prev = *hiter;

    bounds.push( tuple<long,int>(hiter - heights.begin(), *hiter));
    hiter++;

    bounds.push( tuple<long,int>(hiter - heights.begin(), *hiter));
    int vol =0;
    while (hiter != heights.end())
    {
        if (prev < *hiter)
        {
            vol+=process_bounds(bounds,tuple<long,int>(hiter - heights.begin(), *hiter));
            bounds.push( tuple<long,int>(hiter - heights.begin(), *hiter));
        }
        *hiter++;
    }
    return vol;
}

int TrapWater::process_bounds(stack<tuple<long, int>> &bounds,
                   tuple<long, int> upper)
{
    static int base = 0;
    long uindex = get<0>(upper);
    int uval = get<1> (upper);
    while (!bounds.empty() && get<1>(bounds.top()) <= uval)
    {
        auto elem = bounds.top();
        vol+= (uval - (get<1>(elem)) + base)*(uindex-get<0>(elem));
        bounds.pop();
    }
    base = uval;
    if (bounds.size())

}
 */

/*#include "TrapWater.h"
int main()
{
//    std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> heights = {6,5,4,3,2,1,2,3,4,5,6,7,8};

    TrapWater t;
    int vol = t.trap(heights);
    cout << "volume = " <<vol;
}

*/