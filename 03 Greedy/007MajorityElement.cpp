#include<bits/stdc++.h>
using namespace std;

// GFG - Majority Element
// LeetCode - 169

class Solution{
  public:
    int majorityElement(int a[], int n){
        if(n==1)
            return a[0];
        int val = a[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(val==a[i]){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                val = a[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i<n; i++){
            if(val == a[i])
                count++;
        }
        if(count>n/2)
            return val;
        return -1;
    }
};