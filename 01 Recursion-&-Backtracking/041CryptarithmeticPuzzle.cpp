#include<bits/stdc++.h>
using namespace std;

// GFG - Article - https://www.geeksforgeeks.org/solving-cryptarithmetic-puzzles-backtracking-8/
//                 https://www.geeksforgeeks.org/c-code-article-backtracking-set-8-solving-cryptarithmetic-puzzles/
class Solution{
    bool checkCorrect(string s1,string s2, string s3,unordered_map<char,int> &arr){
        int val1=0, val2=0, val3=0;
        int m = 1;
        for(int i = s1.size()-1; i>=0; i--){
            val1+=m*arr[s1[i]];
            m*=10;
        }
        m=1;
        for(int i = s2.size()-1; i>=0; i--){
            val2+=m*arr[s2[i]];
            m*=10;
        }
        m=1;
        for(int i = s3.size()-1; i>=0; i--){
            val3+=m*arr[s3[i]];
            m*=10;
        }
        return (val1+val2)==val3;
    }
    bool isCrypt(int i, int count, string s1,string s2, string s3,unordered_map<char,int> &arr,vector<bool> &used){
        if(i==count){
            return checkCorrect(s1,s2,s3,arr);
        }
        for(int j = 0; j<10; j++){
            if(!used[j]){
                auto it = arr.begin();
                for(int k = 0; k<i; k++){
                    it++;
                }
                (*it).second = j;
                used[j] = true;
                if(isCrypt(i+1,count,s1,s2,s3,arr,used))
                    return true;
                used[j]=false;
            }
        }
        return false;
    }
    public:
    bool crypt(string s1,string s2, string s3){
        unordered_map<char,int> um;
        for(char c: s1)
            um[c]++;
        for(char c: s2)
            um[c]++;
        for(char c: s3)
            um[c]++;
        int count = um.size();
        if(count > 10)
            return false;
        vector<bool> used(10);
        return isCrypt(0,count,s1,s2,s3,um,used);
    }
};

// set-2
// GFG - Article - https://www.geeksforgeeks.org/solving-cryptarithmetic-puzzles-set-2/?ref=rp

class Solution{
    bool isCrypt(int i, int n, string uniq,unordered_map<char,int>&hash,unordered_map<char,int>&mp,unordered_map<char,bool>&first,vector<bool> &used){
        if(i==uniq.size()){
            return n==0;
        }
        char c = uniq[i];
        int val = mp[c];
        if(val != -1)
            return isCrypt(i+1,n+val*hash[c],uniq,hash,mp,first,used);
        
        bool x = false;
        for(int j=0; j<10;j++){
            if((first[c] && j==0) || used[j])
                continue;
            mp[c]=j;
            used[j]=true;
            x|=isCrypt(i+1,n*j*hash[c],uniq,hash,mp,first,used);
            mp.erase(c);
            used[j]=false;
        }
        return x;
    }
    public:
    bool crypt(vector<string> words,string result){
        unordered_map<char,int> hash;
        unordered_map<char,int> mp;
        unordered_map<char,bool> first;
        vector<bool> used(10);
        string uniq = "";

        for(auto word: words){
            int i = 0;
            for(auto c: word){
                hash[c] += (int)pow(10,word.size()-1-i);
                if(mp.find(c)==mp.end()){
                    mp[c] = true;
                    uniq+=c;
                }
                if(i==0 && word.size()>1){
                    first[c]=true;
                }
                i++;
            }
        }
        int i = 0;
        for(auto c: result){
                hash[c] += (int)pow(10,result.size()-1-i);
                if(mp.find(c)==mp.end()){
                    mp[c] = true;
                    uniq+=c;
                }
                if(i==0 && result.size()>1){
                    first[c]=true;
                    i = false;
                }
        }
        mp.clear();       
        return isCrypt(0,0,uniq,hash,mp,first,used);
    }
};