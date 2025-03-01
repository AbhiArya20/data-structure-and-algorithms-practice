#include<bits/stdc++.h>
using namespace std;

// GFG - Aho Corasick Algorithm
// Practice Link - https://nados.io/question/aho-corasick-application?zen=true
class Solution{
    class Node{
        unordered_map<char,Node*> children;
        Node* failure;
        Node* output;
        int indexOfWord;
        public:
        Node(){
            failure = NULL;
            output = NULL;
            indexOfWord = -1;
        }
        bool isContain(char c){
            return children.find(c)!=children.end();
        }
        Node* getChild(char c){
            return children[c];
        }
        void setChild(char c){
            children[c] = new Node();
        }
        void setIndexOfWord(int idx){
            indexOfWord = idx;
        }
        int getIndexOfWord(){
            return indexOfWord;
        }
        void setFailure(Node* whereTogoWhenFailure){
            failure = whereTogoWhenFailure;
        }
        unordered_map<char,Node*> getChildrens(){
            return children;
        }
        Node* getFailure(){
            return failure;
        }
        void setOutput(Node* nodeWhichIsOutput){
            output = nodeWhichIsOutput;
        }
        Node* getOutput(){
            return output;
        }
    };
    Node* root;
    void buildTrie(vector<string> arr){
        int index = 0;
        for(auto word: arr){
            Node* cur = root;
            for(auto c: word){
                if(!cur->isContain(c)){
                    cur->setChild(c);
                }
                cur = cur->getChild(c);
            }
            cur->setIndexOfWord(index);
            index++;
        }
    }
    void failureAndOutputLink(){
        root->setFailure(root);
        queue<Node*> q;

        for(auto childPair : root->getChildrens()){
            auto child = childPair.second;
            q.push(child);
            child->setFailure(root);
        }

        while (!q.empty()){
            auto curNode = q.front();
            q.pop();
            for(auto childPair: curNode->getChildrens()){
                auto child = childPair.second;
                auto ch = childPair.first;
                auto curNodeFailure = curNode->getFailure();
                while(!curNodeFailure->isContain(ch) && curNodeFailure != root){
                    curNodeFailure = curNodeFailure->getFailure();
                }
                if(curNodeFailure->isContain(ch)){
                    child->setFailure(curNodeFailure->getChild(ch));
                }else{
                    child->setFailure(curNodeFailure);
                }
                q.push(child);
            }  
            if(curNode->getFailure()->getIndexOfWord() != -1){
                curNode->setOutput(curNode->getFailure());
            }else{
                curNode->setOutput(curNode->getFailure()->getOutput());
            }
        }        
    }
    vector<vector<int>> getAllAns(string txt, int sizeOfArr){
        vector<vector<int>> ans(sizeOfArr);
        int n = txt.size();
        Node* curNode = root;
        for(int i = 0; i<n; i++){
            char ch = txt[i];
            if(curNode->isContain(ch)){
                curNode = curNode->getChild(ch);
                if(curNode->getIndexOfWord()!=-1){
                    ans[curNode->getIndexOfWord()].push_back(i);
                }
                auto tempCurNode = curNode->getOutput();
                while (tempCurNode){
                    ans[tempCurNode->getIndexOfWord()].push_back(i);
                    tempCurNode = tempCurNode->getOutput();
                }
            }else{
                while (curNode != root && !curNode->isContain(ch)){
                    curNode = curNode->getFailure();
                }
                if(curNode->isContain(ch)) 
                    i--;               
            }
        }
        return ans;
    }
    public:
    vector<vector<int>> ahoCorasick(string txt, vector<string> arr){
        root = new Node();
        int sizeOfArr = arr.size();
        buildTrie(arr);
        failureAndOutputLink();
        return getAllAns(txt,sizeOfArr);
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    string txt;
    cin>>txt;

    Solution obj;
    auto ans = obj.ahoCorasick(txt, arr);
    int index = -1;
    for(auto tempAns : ans){
        index++;
        if(tempAns.size()==0){
            cout<<-1<<endl;
            continue;
        }
        for(auto idx: tempAns){
            cout<<idx-arr[index].size()+1<<" ";
        }
        cout<<endl;
    }
}