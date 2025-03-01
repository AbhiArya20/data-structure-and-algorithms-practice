#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum GCD Pair

class Solution{   
public:
    int MaxGcd(int n, int a[]) { 
        unordered_map<int,int>st;
        int ans = 1;
        for(int i = 0; i<n; i++){
            st[a[i]]++;
            if(st[a[i]]>=2)
                ans = max(ans, a[i]);
        }
        if(ans != 1)
            return ans;
        for(int i = 0; i<n; i++){
            int k = a[i];
            for(int j = 2; j*j<=k; j++){
                if(k%j==0 && st.find(j)!=st.end()){
                    ans = max(ans, min(k,j));
                }
            }
        }
        return ans;
    } 
};