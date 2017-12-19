//
// Created by soumya on 12/4/17.
//

#ifndef ADDTWONUMBERS_MEDIANOFSORTEDARRAYS_H
#define ADDTWONUMBERS_MEDIANOFSORTEDARRAYS_H

#include <vector>
#include <iostream>

using namespace std;

class MedianofSortedArrays {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        double m1=0, m2=0, mloc=0;
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        //mloc+=2;
        while (mloc < (nums1.size() + nums2.size())/2 + 1)
        {
            mloc++;
            if (iter1 != nums1.end() && iter2!=nums2.end()) {
                if (*iter1 <= *iter2) {
                    m2 = m1;
                    m1 = *iter1;
                    *iter1++;
                } else {
                    m2 = m1;
                    m1 = *iter2;
                    *iter2++;
                }
                continue;
            }
            if (iter1 != nums1.end())
            {
                m2 = m1;
                m1 = *iter1;
                iter1++;
                continue;
            }
            if (iter2 != nums2.end()) {
                m2 = m1;
                m1 = *iter2;
                iter2++;
                continue;
            }

        }
//        std::cout << m1 << " " << m2;
        if (!((nums1.size() + nums2.size())%2))
        {
            m1 =1.0 * (m1 + m2)/2;
        }
        return m1;
    }
};


#endif //ADDTWONUMBERS_MEDIANOFSORTEDARRAYS_H
