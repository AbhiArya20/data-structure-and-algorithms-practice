#include<bits/stdc++.h>
using namespace std;

// GFG - Word Ladder 1
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> words;
        words.insert(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        while(!q.empty()){
            auto word = q.front().first;
            auto dist = q.front().second;
            if(word == targetWord)
                return dist;
            q.pop();
            for(auto &c: word){
                auto originalChar = c;
                for(char ch = 'a'; ch<='z'; ch++){
                    c = ch;
                    if(words.find(word)!=words.end()){
                        q.push({word,dist+1});
                        words.erase(word);
                    }
                }
                c = originalChar;
            }
        }
        return 0;
    }
};


// GFG - Word Ladder - II
class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> words;
        words.insert(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({startWord});
        while(!q.empty()){
            int size = q.size();
            vector<string> temp;
            for(int i = 0; i<size; i++){
                auto dist = q.front();
                auto word = dist[dist.size()-1];
                q.pop();
                if(word == targetWord){
                    ans.push_back(dist);
                }
                for(auto &c: word){
                    auto originalChar = c;
                    for(char ch = 'a'; ch<='z'; ch++){
                        c = ch;
                        dist.push_back(word);
                        if(words.find(word)!=words.end()){
                            temp.push_back(word);
                            q.push({dist});
                        }
                        dist.pop_back();
                    }
                    c = originalChar;
                }
            }
            for(auto t: temp){
                words.erase(t);
            }
        }
        return ans;
    }
};