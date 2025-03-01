#include<bits/stdc++.h>
using namespace std;

// GFG - Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
// https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

int maxSum(int arr[], int n){
    int arrSum = 0;
    int currVal = 0;
    for (int i = 0; i < n; i++) {
        arrSum = arrSum + arr[i];
        currVal = currVal + (i * arr[i]);
    }
    int ans = currVal;
    for (int i = 1; i < n; i++) {
        currVal = currVal + arrSum - n * arr[n - i];
        ans = max(ans, currVal);
    }
    return ans;
}