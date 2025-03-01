#include<bits/stdc++.h>
using namespace std;

// GFG - Sort an Array or 0s, 1s, 2s

class Solution
{
    public:
    void sort012(int a[], int n){
        int left = 0,mid=0,right=n-1;
        while(mid<=right){
            if(a[mid]==0){
                swap(a[mid++],a[left++]);
            }else if(a[mid]==1){
                mid++;
            }else{
                swap(a[mid],a[right--]);
            }
        }
    }
    
};