#include<bits/stdc++.h>
using namespace std;

// LeetCode - 23

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        auto ans = dummy;
        priority_queue<ListNode*, vector<ListNode*>,comp> pq;
        for(auto list: lists){
            if(list)
                pq.push(list);
        }
        while(!pq.empty()){
            auto list = pq.top();
            pq.pop();
            dummy->next = list;
            dummy = dummy->next;
            list = list->next;
            if(list)
                pq.push(list);
        }
        return ans->next;
    }
};