#include<bits/stdc++.h>
using namespace std;

// GFG - Quick Sort

class Solution{ // Based On divide and conquer
    int partition (int arr[], int low, int high){
        int pivot = arr[high];
        int i = low-1;
        for(int j = low; j<high; j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    public:
    void quickSort(int arr[], int low, int high){
        if(low<high){
            int pivotPos = partition(arr,low,high);
            quickSort(arr,low,pivotPos-1);
            quickSort(arr,pivotPos+1,high);
        }
    }
};