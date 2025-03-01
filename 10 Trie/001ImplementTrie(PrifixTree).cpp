#include<bits/stdc++.h>
using namespace std;

// LeetCode - 208

struct Node{
    Node* arr[26];
    bool flag = false;
    bool contains(char ch){
        return arr[ch - 'a'];
    }
    void put(char ch, Node* node){
        arr[ch-'a']= node;
    }
    Node* get(char ch){
        return arr[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }
};

class Trie {
  Node* root;
public:
    Trie() {
        root = new Node();      
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contains(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};