#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Common Prefix in an Array

class Solution{
  public:
    string longestCommonPrefix (string arr[], int N){
       string ans=arr[0];
       for(int i=0;i<N;i++){
           int k=0;
           for(k=0;k<ans.length();k++){
               if(arr[i][k]!=ans[k]){ break;}
           }
            ans =ans.substr(0, k);
            if(ans.length()==0) return "-1";
       }
       return ans;
    }
};