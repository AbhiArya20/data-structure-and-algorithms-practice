#include<bits/stdc++.h>
using namespace std;

// GFG - Largest Number in K Swap

/*
    1. Find the largest number from in right of the index where you want to maximize
    2. If(maximumElement != currentElement ) k--;
    3. swap for every occurance of maximumElement them make backtracking calls

*/
class Solution
{
     void backtracking(int i,string str, int k, string &ans){
        ans = max(ans, str);
        if(k==0)
            return;
        char maxi = str[i];
        for(int j = i+1; j<str.size(); j++){
            maxi = max(maxi, str[j]);
        }
        if(maxi!=str[i])
            k--;
        for(int j = str.size()-1; j>=i; j--){
            if(maxi==str[j]){
                swap(str[j],str[i]);
                backtracking(i+1,str,k,ans);
                swap(str[j],str[i]);
            }
        }
    }
    public:
    string findMaximumNum(string str, int k)
    {
       string ans = str;
       backtracking(0, str, k, ans);
       return ans;
    }
}; 