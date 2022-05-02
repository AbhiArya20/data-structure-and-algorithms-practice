#include<bits/stdc++.h>
using namespace std;
#define ll long long

// GFG - Pascal Triangle

class Solution{
    int mod = 1e9+7;
    vector<ll> pascal(int n){
        if(n==1)
            return {1};
        vector<ll> rec = pascal(n-1);
        vector<ll> ans;
        ans.push_back(1);
        for(int i = 1; i<rec.size(); i++){
            ans.push_back((rec[i-1]+rec[i])%mod);
        }
        ans.push_back(1);
        return ans;
    }
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        return pascal(n);
    }
};


