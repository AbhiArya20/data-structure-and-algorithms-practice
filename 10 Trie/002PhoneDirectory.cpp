#include<bits/stdc++.h>
using namespace std;

// GFG - Phone Directory
// LeetCode - Search Suggestions System

class TrieNode{
   int flag;
   unordered_map<char,TrieNode*> childrens;
   string wordEnd;
   public:
   TrieNode(){
       flag = false;
       wordEnd = "";
   }
   bool isContain(char c){
       return childrens.find(c)!=childrens.end();
   }
   void set(char c){
       childrens[c] = new TrieNode();
   }
   TrieNode* get(char c){
       return childrens[c];
   }
   void setWord(string word){
       this->wordEnd = word;
   }
   string getWord(){
       return wordEnd;
   }
   void setFlag(){
       flag = true;
   }
   bool getFlag(){
       return flag;
   }
};
class Trie{
  TrieNode* root;
  public:
  Trie(){
      root= new TrieNode();
  }
  void insert(string word){
      TrieNode* curRoot = root;
      for(auto c: word){
          if(!curRoot->isContain(c))
             curRoot->set(c);
          curRoot = curRoot->get(c);
      }
      curRoot->setWord(word);
      curRoot->setFlag();
  }  
  void recursiveSearch(TrieNode* curNode, vector<string> &ans){
      if(curNode->getFlag()){
          string val = curNode->getWord();
          ans.push_back(val);
      }
      for(char i = 'a'; i<='z'; i++){
          if(curNode->isContain(i)){
              recursiveSearch(curNode->get(i),ans);
          }
      }
  }
  vector<string> search(string word){
      vector<string> ans;
      TrieNode* curRoot= root;
      for(auto c: word){
          if(!curRoot->isContain(c))
             return ans;
          curRoot = curRoot->get(c);
      }
      recursiveSearch(curRoot, ans);
      return ans;
  }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        vector<vector<string>> ans;
        Trie* root = new Trie();
        for(int i = 0; i<n; i++){
            root->insert(contact[i]);
        }
        int m = s.size();
        string st = "";
        for(int i = 0; i<m; i++){
            st+=s[i];
            auto v = root->search(st);
            if(v.size()==0){
                ans.push_back({"0"});
            }else{
                ans.push_back(v);
            }
        }
        return ans;
    }
};