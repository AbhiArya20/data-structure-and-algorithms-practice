#include<bits/stdc++.h>
using namespace std;


// GFG - Sortest Unique prefix for every word

class TrieNode{
  int flag;
  int count;
  TrieNode* childrens[30];
  public:
  TrieNode(){
      flag = false;
      count = 0;
       for(int i=0; i<26; i++)
            childrens[i] = NULL;
  }
  bool isContain(char &c){
      int idx = c-'a';
      return childrens[idx];
  }
  void set(char &c){
      int idx = c-'a';
      childrens[idx] = new TrieNode();
  }
  TrieNode* get(char &c){
      int idx = c-'a';
      return childrens[idx];
  }
  void setFlag(){
      flag = true;
  }
  bool getFlag(){
      return flag;
  }
  void incCount(){
      count++;
  }
  int getCount(){
      return count;
  }
};
class Trie{
  TrieNode* root;
  public:
  Trie(){
      root= new TrieNode();
  }
  void insert(string &word){
      TrieNode* curRoot = root;
      for(auto &c: word){
          if(!curRoot->isContain(c)){
             curRoot->set(c);
          }
          curRoot = curRoot->get(c);
          curRoot->incCount();
      }
      curRoot->setFlag();
  }  
  string search(string &word){
      int ans = 0;
      TrieNode* curRoot= root;
      string st = "";
      for(auto &c: word){
          st+=c;
          curRoot = curRoot->get(c);
          int count = 0;
          for(char i = 'a'; i<='z'; i++){
              if(curRoot->isContain(i) && curRoot->getCount()==1)
                count++;
          }
          if(count==1){
            return st;
          }
      }
      return word;
  }
};
class Solution{
    public:
    vector<string> findPrefixes(string *arr, int n){
        vector<string> ans(n);
        Trie* root = new Trie();
        for(int i = 0; i<n; i++){
            root->insert(arr[i]);
        }
        for(int i = 0; i<n; i++){
            ans[i] = root->search(arr[i]);
        }
        return ans;
    }
};
