#include<bits/stdc++.h>
using namespace std;

// GFG - Selection Sort

class Solution{
    public:
    void selectionSort(int arr[], int n){
       for(int i = 0; i<n; i++){
           int min_idx=i;
           for(int j = i+1;j<n; j++){
               if(arr[j]<arr[min_idx])
                    min_idx = j;
           }
           if(min_idx != i)
                swap(arr[min_idx], arr[i]);
       }
    }
};