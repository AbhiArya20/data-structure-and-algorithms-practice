#include<bits/stdc++.h>
using namespace std;

// GFG - Merge Sort

class Solution{ // Based On divide and conquer
    public:
    void merge(int arr[], int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r - m;
        int left[n1],right[n2];
        for(int i = 0; i<n1; i++){
            left[i] = arr[i+l];
        }
        for(int i = 0; i<n2; i++){
            right[i] = arr[m+1+i];
        }
        int k = l;
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            if(left[i]<right[j]){
                arr[k++] = left[i++];
            }else{
                arr[k++] = right[j++];
            }
        }
        while(i<n1){
            arr[k++] = left[i++];
        }
        while(j<n2){
            arr[k++] = right[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r){
        if(l<r){
            int mid = (l+r)>>1;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};