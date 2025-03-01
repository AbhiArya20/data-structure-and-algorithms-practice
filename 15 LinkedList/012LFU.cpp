#include<bits/stdc++.h>
using namespace std;

// LeetCode - 460

class LFUCache {
    struct DoublyLinkedListNode{
        int value, key, freq;
        DoublyLinkedListNode* next;
        DoublyLinkedListNode* prev;
        DoublyLinkedListNode(int key, int value, int freq){
            this->key = key;
            this->value = value;
            this->freq = freq;
            next = NULL;
            prev = NULL;
        }
    };
    struct DoublyLinkedList{
        int size = 0;
        DoublyLinkedListNode* head;
        DoublyLinkedListNode* tail;
        DoublyLinkedList(){
            head = new DoublyLinkedListNode(-1,-1,-1);
            tail = new DoublyLinkedListNode(-1,-1,-1);
            head->next = tail;
            tail->prev = head;
        }
        void deleteANode(DoublyLinkedListNode* node){
            size--;
            auto prev = node->prev;
            auto next = node->next;
            prev->next = next;
            next->prev = prev;
            delete node;
        }
        DoublyLinkedListNode* addRecent(int key, int value,int freq){
            size++;
            DoublyLinkedListNode* newNode = new DoublyLinkedListNode(key,value,freq);
            newNode->next = head->next;
            newNode->prev = head;
            head->next->prev = newNode;
            head->next = newNode;
            return newNode;
        }
    };
    int capacity;
    int minFreq;
    unordered_map<int,DoublyLinkedListNode*> um;
    unordered_map<int,DoublyLinkedList*> freqmap;
    void updateLFU(DoublyLinkedListNode *curNode, int value){
        int key = curNode->key;
        int freq = curNode->freq;
        freqmap[freq]->deleteANode(curNode);
        if(freqmap[minFreq]->size==0)
            minFreq++;
        freq++;
        if(freqmap.find(freq)==freqmap.end())
            freqmap[freq] = new DoublyLinkedList();
        auto newNode = freqmap[freq]->addRecent(key,value,freq);
        um[key] = newNode;
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }    
    int get(int key) {
        if(um.find(key)==um.end())
            return -1;
        auto curNode = um[key];
        int value = curNode->value;
        updateLFU(curNode,value);
        return value;
    }    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(um.find(key)!=um.end()){
            auto curNode = um[key];
            updateLFU(curNode,value);
        }else if(um.size() == capacity){
            auto curDel = freqmap[minFreq]->tail->prev;
            um.erase(curDel->key);
            freqmap[minFreq]->deleteANode(curDel);
            minFreq = 1;
            auto newNode = freqmap[minFreq]->addRecent(key,value,minFreq);
            um[key] = newNode;
        }else{
            minFreq = 1;
            if(freqmap.find(minFreq)==freqmap.end())
                freqmap[minFreq] = new DoublyLinkedList();
            auto newNode = freqmap[minFreq]->addRecent(key,value,minFreq);
            um[key] = newNode;
        }
    }
};



class LFUCache { // Small implementation using STL list(doubly linkedlist) container
    int capacity;
    int minFreq;
    unordered_map<int,list<vector<int>>> freqmap;
    unordered_map<int,list<vector<int>>::iterator> um;
    void updateLFU(list<vector<int>>::iterator curNode, int value){
        int key = (*curNode)[0];
        int freq = (*curNode)[2];
        freqmap[freq].erase(curNode);
        if(freqmap[minFreq].size()==0)
            minFreq++;
        freq++;
        if(freqmap.find(freq)==freqmap.end()){
            list<vector<int>> li;
            freqmap[freq] = li;
        }
        freqmap[freq].insert(freqmap[freq].begin(),{key,value,freq});
        um[key] = freqmap[freq].begin();
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }    
    int get(int key) {
        if(um.find(key)==um.end())
            return -1;
        auto curNode = um[key];
        int value = (*curNode)[1];
        updateLFU(curNode,value);
        return value;
    }    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(um.find(key)!=um.end()){
            auto curNode = um[key];
            updateLFU(curNode,value);
        }else if(um.size() == capacity){
            auto curDel = freqmap[minFreq].end();
            curDel--;
            um.erase((*curDel)[0]);
            freqmap[minFreq].erase(curDel);
            minFreq = 1;
            freqmap[minFreq].insert(freqmap[minFreq].begin(),{key,value,minFreq});
            um[key] = freqmap[minFreq].begin();
        }else{
            minFreq = 1;
            if(freqmap.find(minFreq)==freqmap.end()){
                list<vector<int>> li;
                freqmap[minFreq] = li;
            }
            freqmap[minFreq].insert(freqmap[minFreq].begin(),{key,value,minFreq});
            um[key] = freqmap[minFreq].begin();
        }
    }
};



// LeetCode - 432

class AllOne { // O(LogN) - Accepted but not according to question
    set<pair<int,string>> st;
    unordered_map<string,int> mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int c = mp[key];
        auto it = st.find({c,key});
        mp[key]++;
        st.insert({c+1,key});
        if(it!=st.end())
            st.erase(it);
    }
    
    void dec(string key) {
        int c = mp[key];
        auto it = st.find({c,key});
        mp[key]--;
        if(mp[key]==0){
            mp.erase(key);
        }else{
            st.insert({c-1,key});
        }
        st.erase(it);
    }
    
    string getMaxKey() {
        if(st.size()==0)
            return "";
        return (*st.rbegin()).second;
    }
    
    string getMinKey() {
        if(st.size()==0)
            return "";
        return (*st.begin()).second;
    }
};