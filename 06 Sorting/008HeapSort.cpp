#include<bits/stdc++.h>
using namespace std;

// GFG - Heap Sort 

class Solution{
    void heapify(int arr[], int n, int i)  {
        int largest = i;
        int left = i*2+1; 
        int right = i*2+2;
        
        if(left<n && arr[left]>arr[largest])
            largest = left;
        if(right<n && arr[right]>arr[largest])
            largest = right;
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr,n,largest);
        }
    }
    void buildHeap(int arr[], int n)  { 
        for(int i = n/2-1; i>=0; i--){
            heapify(arr,n,i);
        }
        for(int i = n-1; i>0; i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
    }
    public:
    void heapSort(int arr[], int n){
       buildHeap(arr,n);
    }
};