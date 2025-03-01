#include<bits/stdc++.h>
using namespace std;

// LeetCode - 160
// GFG - Intersection Point in Y Shapped Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_map<ListNode*,int> um;
        while(head1){
            um[head1]++;
            head1 = head1->next;
        }
        while(head2){
            if(um.find(head2)!=um.end())
                return head2;
            head2 = head2->next;
        }
        return NULL;
    }
};


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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1 = length(head1);
        int len2 = length(head2);
        if(len2>len1){
            swap(head1,head2);
            swap(len1,len2);
        }
        int dif = len1 - len2;
        while(dif){
            head1 = head1->next;
            dif--;
        }
        while(head1 && head2){
            if(head1==head2){
                return head1;
            }
            head1= head1->next;
            head2= head2->next;
        }
        return NULL;
    }
};