#include<bits/stdc++.h>
using namespace std;

// GFG - Assembly Line Scheduling

class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x){
      int n = a[0].size();
      if(n==1)
         return min(e[0]+a[0][0]+x[0],e[1]+a[1][0]+x[1]);
      vector<int> first(n),second(n);
      first[n-1] = x[0] + a[0][n-1];
      second[n-1] = x[1] + a[1][n-1];
      for(int i = n-2; i>0; i--){
          first[i] = a[0][i] + min(first[i+1], second[i+1]+t[0][i+1]);
          second[i] = a[1][i] + min(second[i+1], first[i+1]+t[1][i+1]);
      }
      first[0] = e[0] + a[0][0] + min(first[1], second[1]+t[0][1]);
      second[0] = e[1] + a[1][0] + min(second[1], first[1]+t[1][1]);
      return min(first[0],second[0]);
  }
};