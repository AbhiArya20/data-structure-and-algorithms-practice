#include<bits/stdc++.h>
using namespace std;

// LeetCode - 725


class Solution {
    int length(ListNode* head){
        int ans = 0;
        while(head){
            ans++;
            head = head->next;
        }
        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(k==1)
            return {head};
        int len = length(head);
        vector<ListNode*> ans;
        if(len<=k){
            ListNode* cur = head;
            ListNode* next = head;
            while(next){
                cur = next;
                next = next->next;
                cur->next = NULL;
                ans.push_back(cur);
                k--;
            }
            while(k--)
                ans.push_back(NULL);
        }else{
            int part = len/k;
            int ext = len-part*k;
            ListNode* cur = head;
            ListNode* next = head;
            while(true){
                int size = part-1;
                if(ext){
                    size++;
                    ext--;
                }
                while(size--){
                    next = next->next;
                }
                ans.push_back(cur);
                if(next && next->next){
                    ListNode* toNext = next->next;
                    next->next = NULL;
                    cur = toNext;
                    next = cur;
                }else{
                    goto label;
                }
            }
            label:;
        }
        return ans;
    }
};

