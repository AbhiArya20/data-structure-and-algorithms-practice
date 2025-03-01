#include<bits/stdc++.h>
using namespace std;

// GFG - Rearrange Array Alternately

class Solution{
    public:
    void rearrange(long long *arr, int n){ 
        int i = 0;
        int j = n-1;
        int maxi = *max_element(arr, arr+n)+1;
        for(int k = 0; k<n; k++){
            if(k&1){
                arr[k] = arr[k]*maxi+(arr[i]/maxi);
                i++;
            }else{
                if(j<k){
                    arr[k] = arr[k]*maxi+(arr[j]/maxi);
                }else{
                    arr[k] = arr[k]*maxi+arr[j];
                }
                j--;
            }
        }
        for(int i = 0; i<n; i++){
            arr[i] %= maxi;
        }
    }
};