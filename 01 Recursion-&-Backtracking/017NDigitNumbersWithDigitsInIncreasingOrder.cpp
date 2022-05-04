#include<bits/stdc++.h>
using namespace std;

// GFG - N Digit numbers with digits in increasing order

class Solution{
    void getAll(int i,int temp, int n, vector<int> & ans){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j<=9; j++){
            getAll(j+1,temp*10+j, n-1, ans);
        }
        
    }
public:
    vector<int> increasingNumbers(int N)
    {
        vector<int> ans;
        if(N==1)
            ans.push_back(0);
        getAll(1,0,N,ans);
        return ans;
    }
};