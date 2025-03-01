#include<bits/stdc++.h> 
using namespace std;

// GFG - Permutation Coefficient

class Solution{
  int npc(int n, int k){
    int ans = 1;
    for(int i = 0; i < k; i++)
        ans *= (n-i);
    return ans;
  }
};
