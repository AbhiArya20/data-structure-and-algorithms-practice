#include<bits/stdc++.h>
using namespace std;

// GFG - Count Subarrays with given XOR

class Solution{
    public:
        int subarraysXor(vector<int> &A, int x){
            int xors = 0;
            int ans = 0;
            int n1 = A.size();
            unordered_map<int,int> um;
            um[0]++;
            for(int i = 0; i<n1; i++){
                xors^=A[i];
                ans += um[xors^x];
                um[xors]++;
            }
            return ans;
        }
}