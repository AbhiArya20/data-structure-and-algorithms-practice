#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2508

class Solution {
    vector<int> getSecondPair(vector<int> &odd, int taken){
        vector<int> ans;
        for(int i = 1; i<4; i++){
            if(i==taken)
                continue;
            ans.push_back(odd[i]);
        }
        return ans;
    }
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        set<vector<int>> st;
        vector<int> indegre(n+1);
        for(auto edge: edges){
            indegre[edge[0]]++;
            indegre[edge[1]]++;
            st.insert({edge[0],edge[1]});
            st.insert({edge[1],edge[0]});
        }
        vector<int> odd;
        for(int i = 1; i<=n; i++)
            if(indegre[i]%2)
                odd.push_back(i);
        int oddLen = odd.size();
        if(oddLen==0)
            return true;
        if(oddLen==2){
            for(int i = 1; i<=n; i++){
                auto pair1 = {odd[1],i};
                auto pair2 = {odd[0],i};
                if(st.find(pair1)==st.end() && st.find(pair2)==st.end())
                    return true;
            }
        }
        if(oddLen==4){
            for(int i = 1; i<4; i++){
                auto pair1 = {odd[0],odd[i]};
                auto pair2 = getSecondPair(odd,i);
                if(st.find(pair1)==st.end() && st.find(pair2)==st.end())
                    return true;
            }
        }
        return false;
    }
};