#include<bits/stdc++.h>
using namespace std;

// GFG - Rotate A Linked List
// LeetCode - 61

class Solution{
    Node *reverseList(Node *head){
        if (!head || !head->next)
            return head;
        Node *prev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return prev;
    }
    public:
    Node* rotate(Node* head, int k){
        Node* half = head;
        k--;
        while(k){
            half = half->next;
            k--;
        }
        Node* half2 = half->next;
        half->next = NULL;
        half2 = reverseList(half2);
        head = reverseList(head);
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = half2;
        return reverseList(head);
    }
};