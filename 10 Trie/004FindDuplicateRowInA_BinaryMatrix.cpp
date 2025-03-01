#include<bits/stdc++.h>
using namespace std;

// GFG - Find Duplicate row in a binary matrix

class TrieNode{
  int flag;
  int count;
  TrieNode* childrens[2];
  public:
  TrieNode(){
      flag = false;
      for(int i=0; i<2; i++)
         childrens[i] = NULL;
  }
  bool isContain(int &c){
      return childrens[c];
  }
  void set(int &c){
      childrens[c] = new TrieNode();
  }
  TrieNode* get(int &c){
      return childrens[c];
  }
  void setFlag(){
      flag = true;
  }
  int getFlag(){
      return flag;
  }
};
class Trie{
  TrieNode* root;
  public:
  Trie(){
      root= new TrieNode();
  }
  bool insert(vector<int> &word){
      TrieNode* curRoot = root;
      for(auto &c: word){
          if(!curRoot->isContain(c)){
             curRoot->set(c);
          }
          curRoot = curRoot->get(c);
      }
      if(!curRoot->getFlag()){
          curRoot->setFlag();
          return false;
      }
      else{
          return true;
      }
  }
};

class Solution{
    public:
        vector<int> repeatedRows(vector<vector<int>> matrix, int n, int m) { 
            vector<int> ans;
            Trie* root = new Trie();
            for(int i = 0; i<n; i++){
                if(root->insert(matrix[i]))
                    ans.push_back(i);
            }
            return ans;
        }
};