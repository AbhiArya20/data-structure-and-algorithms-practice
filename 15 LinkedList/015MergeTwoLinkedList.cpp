#include<bits/stdc++.h>
using namespace std;

// LeetCode - 21
// GFG - Merge Two Sortest Linked List

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1000);
        ListNode* pointer = dummy;
        while(list1 && list2){
            while(list1 && list2 && list1->val<=list2->val){
                pointer->next = list1;
                list1 = list1->next;
                pointer = pointer->next;
            }
            swap(list1, list2);
        }
        if(list1){
            pointer->next = list1;
        }
        else if(list2){
            pointer->next = list2;
        }
        return dummy->next;
    }
};