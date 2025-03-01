#include<bits/stdc++.h>
using namespace std;

// LeetCode - 146

class LRUCache {
    struct DoublyLinkedList{
        int value, key;
        DoublyLinkedList* next;
        DoublyLinkedList* prev;
        DoublyLinkedList(int key, int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };
    int capacity;
    unordered_map<int,DoublyLinkedList*> um;
    DoublyLinkedList* head;
    DoublyLinkedList* tail;

    void deleteANode(DoublyLinkedList* node){
        auto prev = node->prev;
        auto next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }
    DoublyLinkedList* addRecent(int key, int value){
        DoublyLinkedList* newNode = new DoublyLinkedList(key,value);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        return newNode;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DoublyLinkedList(-1,-1);
        tail = new DoublyLinkedList(-1,-1);
        head->next = tail;
        tail->prev = head;
    }    
    int get(int key) {
        if(um.find(key)==um.end())
            return -1;
        auto curNode = um[key];
        int value = curNode->value;
        deleteANode(curNode);
        auto newNode = addRecent(key,value);
        um[key] = newNode;
        return value;
    }    
    void put(int key, int value) {
        if(um.find(key)!=um.end()){
            auto curNode = um[key];
            deleteANode(curNode);
            auto newNode = addRecent(key,value);
            um[key] = newNode;
        }else if(um.size() == capacity){
            um.erase(tail->prev->key);
            deleteANode(tail->prev);
            auto newNode = addRecent(key,value);
            um[key] = newNode;
        }else{
            auto newNode = addRecent(key,value);
            um[key] = newNode;
        }
    }
};