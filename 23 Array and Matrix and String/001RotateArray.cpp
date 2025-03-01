#include<bits/stdc++.h>
using namespace std;


// GFG - Rotate Array - left
class Solution{ // Reversal Algorithm
    public:
    void rotateArr(int arr[], int d, int n){
        d%=n;
        reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);
        return;
    }
};

// LeetCode - 189 - right
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k%=n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.begin()+k);
        return;
    }
};

class Solution{ // Junggling Algorithm
    public:
    void rotateArr(int arr[], int d, int n){
        d %= n;
        int x = __gcd(n,d);
        for(int i = 0; i<x; i++){
            int temp = arr[i];
            int j = i;
            while(1){
                int d = (j+k)%n;
                if(d==i)
                    break;
                arr[j] = arr[d];
                j = k;
            }
            arr[j] = temp;
        }
    }
};