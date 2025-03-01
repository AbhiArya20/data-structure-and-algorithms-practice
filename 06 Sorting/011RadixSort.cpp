#include<bits/stdc++.h>
using namespace std;

// GFG - Radix Sort

class Solution{
    void countingSort(vector<int> &arr, int idx){
        int n = arr.size();
        vector<int> count(10);

        for(int i = 0; i<n; i++){
            count[(arr[i]/idx)%10]++;
        }

        for(int i = 1; i<10; i++){
            count[i]+=count[i-1];
        }

        vector<int> ans(n);
        for(int i = n-1; i>=0; i--){
            ans[count[(arr[i]/idx)%10]-1] = arr[i];
            count[(arr[i]/idx)%10]--;
        }

        for(int i = 0; i<n; i++)
            arr[i] = ans[i];
    }

    public:

    void radixSort(vector<int> &arr){
        int n = arr.size();

        int maxi = *max_element(arr.begin(),arr.end());

        for(int i = 1; maxi/i>0; i*=10){
            countingSort(arr, i);
        }
    }
};