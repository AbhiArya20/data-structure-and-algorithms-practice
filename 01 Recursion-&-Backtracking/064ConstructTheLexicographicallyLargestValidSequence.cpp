#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1718

class Solution {
    unordered_set<int> um;
    bool getAns(int n,int index,int lastIndex,vector<int> &ans){
        if(index>=lastIndex)
            return true;
        if(ans[index]!=-1)
            return getAns(n,index+1,lastIndex,ans);
        for(int i = n; i>=1; i--){
            if(ans[index] == -1 && um.find(i)==um.end()){
                if(i==1){
                    um.insert(i);
                    ans[index] = i;
                    if(getAns(n,index+1,lastIndex,ans))
                        return true;
                    ans[index] = -1;
                    um.erase(i);    
                }else if(index+i<lastIndex && ans[index+i]==-1){
                    um.insert(i);
                    ans[index] = i;
                    ans[index+i] = i;
                    if(getAns(n,index+1,lastIndex,ans))
                        return true;
                    ans [index] = -1;
                    ans [index+i] = -1;
                    um.erase(i);
                }
            }            
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*(n-1)+1,-1);
        getAns(n, 0,2*(n-1)+1, ans);    
        return ans;
    }
};