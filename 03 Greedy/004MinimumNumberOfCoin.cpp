#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Number of Coin

class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> v = {2000,500,200,100,50,20,10,5,2,1};
        vector<int> ans;
        int i = 0;
        while(N){
            if(N<v[i]){
                i++;
                continue;
            }
            ans.push_back(v[i]);
            N-=v[i];
        }
        return ans;
    }
};
