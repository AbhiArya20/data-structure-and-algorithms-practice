#include<bits/stdc++.h>
using namespace std;
// similar approach in "WORD BOGGLE/WORD BOGGLE-2" on GFG with little-bit changes in code

// LeetCode - 79
// GFG - Word Boggle
class Solution {
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word,int n, int m){
        if(k==word.size())
            return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j] != word[k]){
            return false;
        }
        char c = board[i][j];
        board[i][j] = '.';
        vector<pair<int,int>> v = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto ch: v){
            if(word[k]==c && dfs(i+ch.first,j+ch.second,k+1,board,word,n,m))
                return true;
        }
        board[i][j] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && dfs(i,j,0,board,word,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};


// LeetCode - Word Search II
// GFG - Word Boggle-2

struct Node{
    char c;
    Node* arr[26];
    string word;
    int end;
    Node(char _c){
        word = "";
        c = _c;
        end = 0;
        for(int i = 0;i<26; i++){
            arr[i]=NULL;
        }
    }
    bool contains(char ch){
        return arr[ch - 'a'];
    }
    void increaseEnd(){
        end++;
    }
    void decreaseEnd(){
        end--;
    }
    int getEnd(){
        return end;
    }
    string getWord(){
        return word;
    }
    void setWord(string _word){
        word = _word;
    }
    void setNode(char c){
        arr[c-'a'] = new Node(c);
    }
    Node* getNode(char c){
        return arr[c-'a'];
    }
    Node** getArr(){
        return arr;
    }
    char getC(){
        return c;
    }
};
class Solution {
    void insert(string word,Node* root){
        Node* temp = root;
        for(char c: word){
            if(!temp->contains(c))
                temp->setNode(c);
            temp = temp->getNode(c);
        }
        temp->increaseEnd();
        temp->setWord(word);
    }
    void find(int i, int j, int n, int m, Node* root, vector<vector<char>> &board,vector<string> &ans){
        if(i<0 || j<0 || i==n || j==m)
            return;
        char curBoardvalue = board[i][j];
        int idx = curBoardvalue - 'a';
        if(board[i][j]=='#' || root->getArr()[idx]==NULL)
            return;
        root = root->getArr()[idx];
        if(root->getEnd()){
            ans.push_back(root->getWord());
            root->decreaseEnd();
        }
        board[i][j] = '#';
        find(i-1,j,n,m,root,board,ans);
        find(i+1,j,n,m,root,board,ans);
        find(i,j-1,n,m,root,board,ans);
        find(i,j+1,n,m,root,board,ans);
        board[i][j]=curBoardvalue;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Node* root = new Node('/');
        vector<string> ans;
        for(auto word: words)
            insert(word,root);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                find(i,j,n,m,root,board,ans);
            }
        }
        return ans;
    }
};
