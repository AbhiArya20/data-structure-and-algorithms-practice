#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1545
class Solution {
    string findStr(int n){
        if(n==1){
            return "0";
        }
        string st = findStr(n-1);
        string st1 = st;
        for(int i = 0; i<st1.size(); i++){
            if(st1[i]=='1'){
                st1[i] = '0';
            }else{
                st1[i] = '1';
            }
        }
        reverse(st1.begin(), st1.end());
        return st+"1"+st1;
    }
public:
    char findKthBit(int n, int k) {
        string st = findStr(n);
        cout<<st<<endl;
        return st[k-1];
    }
};