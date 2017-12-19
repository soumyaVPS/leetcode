//
// Created by soumya on 12/4/17.
//

#ifndef ADDTWONUMBERS_ADD_H
#define ADDTWONUMBERS_ADD_H
//
// Created by soumya on 12/4/17.
//

#ifndef ADDTWONUMBERS_ADDTWONUMBERS_H
#define ADDTWONUMBERS_ADDTWONUMBERS_H
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
void printList(ListNode* l)
{
    std::cout << std::endl;
    while (l!= nullptr)
    {
        std::cout << l->val;
        l = l->next;
    }
}

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *p = l3;
        int carry = 0;
        while (carry || l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                l3->val = (l1->val+ l3->val);
                l1= l1->next;
            }
            if (l2 != nullptr)
            {
                l3->val = (l2->val+ l3->val);
                l2=l2->next;
            }
            carry = (l3->val)/10;
            l3->val = l3->val%10;
            if(carry || l1 != nullptr || l2 != nullptr)
            {
                l3->next = new ListNode(carry);
                l3= l3->next;
            }
        }
        return p;
    }
};
ListNode* makeNode(int num) {
    ListNode *p = nullptr;
    ListNode *l1 = new ListNode(0);
    p = l1;
    do {
        p->val = num%10;
        num = num/10;
        p->next = new ListNode(0);
        p = p->next;
    } while (num != 0);

    return l1;
}

#endif //ADDTWONUMBERS_ADDTWONUMBERS_H

#endif //ADDTWONUMBERS_ADD_H
