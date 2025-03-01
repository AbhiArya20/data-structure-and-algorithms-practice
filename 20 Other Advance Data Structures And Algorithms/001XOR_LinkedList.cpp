#include<bits/stdc++.h>
using namespace std;

// GFG - XOR Linked List

class Node{
    int data;
    Node* npx;
    public:
    Node(int data){
        this->data = data;
        npx = NULL;
    }
    void update_NPX(Node* npx){
        this->npx = npx;
    }
    Node* getNPX(){
        return this->npx;
    }
    int getData(){
        return this->data;
    }
};

class LinkedList{
    Node* XOR(Node* prev, Node* next){
        return (Node *)(((uintptr_t)(prev) ^ (uintptr_t)(next)));
    }
    Node* head;
    Node* cur;
    int size;
    LinkedList(){
        head = cur;
        size = 0;
    }
    public:
    void insert(int data){
        Node* newNode = new Node(data);
        newNode->update_NPX(XOR(cur->getNPX(), NULL));
        if(cur!=NULL){
             cur->update_NPX(XOR(cur->getNPX(),newNode));
        }
        cur = newNode;
    }
    void print(){
        Node * cur = head;
        Node* prev = NULL;
        while (cur){
            cout<<cur->getData()<<" ";
            Node* next = XOR(cur->getNPX(), prev);
            prev = cur;
            cur = next;
        }
    }
};
