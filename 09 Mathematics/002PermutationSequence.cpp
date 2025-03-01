#include<bits/stdc++.h>
using namespace std;

// LeetCode - 60

/*

    1. find next-permutation k time on same string

*/
class Solution {
    string nextPer(string st){ 
        int n = st.size();
        int i = n-2;
        while(i>=0 && st[i]>=st[i+1]){
            i--;
        }
        int j = n-1;
        while(j>i && st[j]<=st[i]){
            j--;
        }
        swap(st[i], st[j]);        
        reverse(st.begin()+i+1, st.end());
        return st;
    }
public:
    string getPermutation(int n, int k) {
        string st = "";
        for(int i = 1; i<=n; i++){
            st+=to_string(i);
        }
        for(int i = 1; i<k; i++){
            st = nextPer(st);
        }
        return st;
    }
};