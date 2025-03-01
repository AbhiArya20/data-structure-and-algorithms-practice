#include<bits/stdc++.h>
using namespace std;

// GFG - Count Inversions

class Solution{
    long long int merge(long long arr[],long long temp[], long long l, long long m, long long r){
        long long int count = 0;
        int k = l;
        int i = l;
        int j = m+1;
        while(i<=m && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }else{
                count += m-i+1;
                temp[k++] = arr[j++];
            }
        }
        while(i<=m){
            temp[k++] = arr[i++];
        }
        while(j<=r){
            temp[k++] = arr[j++];
        }
        for(int i = l; i<=r; i++)
            arr[i] = temp[i];
        return count;
    }
    public:
    long long int mergeSort(long long arr[], long long temp[],long long l, long long r){
        long long int count = 0;
        if(l<r){
            long long mid = (l+r)>>1;
            count += mergeSort(arr,temp,l,mid);
            count += mergeSort(arr,temp,mid+1,r);
            count += merge(arr,temp,l,mid,r);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr,temp,0,N-1);
    }

};