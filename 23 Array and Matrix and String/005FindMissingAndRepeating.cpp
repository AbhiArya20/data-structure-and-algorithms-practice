#include<bits/stdc++.h>
using namespace std;

// GFG - Find Missing And Repeating

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        for(int i = 0; i<n; i++){
            int curpos = arr[i]-1;
            if(arr[i]!=arr[curpos]){
                swap(arr[i],arr[curpos]);
                i--;
            }
        }
        int *ans = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        for(int i = 0; i<n; i++){
            if(arr[i]-1 != i){
                ans[0] = arr[i];
                ans[1] = i+1;
                return ans;
            }
        }
        return ans;
    }
};