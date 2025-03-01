#include<bits/stdc++.h>
using namespace std;

// Remove loop in Linked List
// LeetCode - 142
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
    }
};

class Solution{
    Node* detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    Node* getCyclePos(Node* head, Node* detectedNode){
        Node* first = head;
        Node* found = detectedNode;
        while(first != found){
            found = found->next;
            first = first->next;
        }
        return first;
    }
    void removeNode(Node* cycleStartAt, Node* found){
        while(found->next != cycleStartAt){
            found = found->next;
        }
        found->next = NULL;
    }
    public:
    void removeLoop(Node* head){
        auto found = detectLoop(head);
        if(!found)
            return;
        auto cycleStartAt = getCyclePos(head, found);
        removeNode(cycleStartAt,found);
        return;
    }
};


















