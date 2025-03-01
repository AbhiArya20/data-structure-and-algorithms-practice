#include<bits/stdc++.h>
using namespace std;

// GFG - Allocate minimum number of pages

class Solution {
    bool isPos(int mid, int a[], int n, int m){
        int sum = 0;
        int student = 1;
        for(int i = 0; i<n; i++){
            if(a[i]>mid)
                return false;
            if(sum+a[i]>mid){
                sum = 0;
                student++;
            }
            sum+=a[i];
        }
        return student<=m;
    }
    public:
    int findPages(int a[], int n, int m) {
        if(m>n)
            return -1;
        int left = *min_element(a,a+n);    
        int right = accumulate(a,a+n,0);
        int ans = -1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(isPos(mid,a,n,m)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};


// The Painter's Partition Problem II

class Solution {
    bool isPos(long long int mid, int a[], int n, int m){
        long long int sum = 0;
        int student = 1;
        for(int i = 0; i<n; i++){
            if(a[i]>mid)
                return false;
            if(sum+a[i]>mid){
                sum = 0;
                student++;
            }
            sum+=a[i];
        }
        return student<=m;
    }
    public:
    long long minTime(int a[], int n, int m){
        long long int sum = 0;
        long long int left = 0;    
        long long int right = accumulate(a,a+n,sum);
        long long int ans = -1;
        while(left<=right){
            long long int mid = (left+right)>>1;
            if(isPos(mid,a,n,m)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};
