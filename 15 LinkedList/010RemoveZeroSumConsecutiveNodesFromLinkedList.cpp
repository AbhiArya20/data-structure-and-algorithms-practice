#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1171


class Solution { // Approach that i got
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr,ans;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        ans = arr;
        int zero = true;
        while(zero){
            zero = false;
            int n = arr.size();
            int start = -1, end = -1;
            for(int i = 0; i<n; i++){
                int sum = 0;
                for(int j = i; j<n; j++){
                    sum+=arr[j];
                    if(sum==0){
                        start = i;
                        end = j;
                    }
                }
                if(start != -1){
                    break;
                }
            }
            if(start != -1){
                zero = true;
                ans.clear();
                for(int i = 0; i<n; i++){
                    if(i>=start && i<=end)
                        continue;
                    ans.push_back(arr[i]);
                }
                arr = ans;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        for(int i = 0; i<ans.size(); i++){
            cur->next = new ListNode(ans[i]);
            cur = cur->next;
        }
        return dummy->next;
    }
};



class Solution { // Optimal Solution
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        unordered_map<int,ListNode*> um;
        um[0] = dummy;
        int prefixSum = 0;
        while(head){
            prefixSum+=head->val;
            if(um.find(prefixSum)!=um.end()){
                ListNode *prev = um[prefixSum];
                int sum = prefixSum;
                while(prev!=head){
                    prev = prev->next;
                    sum+=prev->val;
                    if(prev != head)
                        um.erase(sum);
                }
                um[prefixSum]->next = head->next;
            }else{
                um[prefixSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};


class Solution { // Optimal Solution
public:
     ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* i = dummy; i; i = i->next) {
            seen[prefix += i->val] = i;
        }
        prefix = 0;
        for (ListNode* i = dummy; i; i = i->next) {
            i->next = seen[prefix += i->val]->next;
        }
        return dummy->next;
    }
};