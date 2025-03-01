#include<bits/stdc++.h>
using namespace std;

// LeetCode - 143
// GFG - Reorder List

class Solution{ 
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            prevSlow = slow;
            slow = slow->next;
        }
        ListNode* second  = reverse(slow);
        prevSlow->next = NULL;
        ListNode* first = head;
        while(first){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first->next = second;
            if(firstNext && secondNext)
                second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
    }
};