#include<bits/stdc++.h>
using namespace std;

// GFG - Activity Selection
// GFG - N-Meeting in one room
class Solution{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++){
            temp.push_back({start[i],end[i]});
        }
        sort(temp.begin(),temp.end(),[](auto a, auto b){
            return a.second<b.second;
        });
        int ans = 1;
        int prev = temp[0].second;
        for(int i = 1; i<n; i++){
            if(temp[i].first>prev){
                ans++;
                prev = temp[i].second;
            }
        }
        return ans;
    }
};