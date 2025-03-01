#include<bits/stdc++.h>
using namespace std;

// GFG - Convert Array Into Zig-Zag Fashion

class Solution {
  public:
    void zigZag(int arr[], int n) {
        for(int i = 1; i<n; i+=2){
            if(arr[i-1]>arr[i])
                swap(arr[i-1],arr[i]);
            if(arr[i+1]>arr[i])
                swap(arr[i+1],arr[i]);
        }
    }
};