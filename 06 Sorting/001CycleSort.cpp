#include<bits/stdc++.h>
using namespace std;

// GFG - Cycle Sort

int cycleSort(int A[], int n){
    for(int i = 0; i<n-1; i++){
        int correctPos = A[i]-1;
        if(A[i]!=A[correctPos]){
            swap(A[i],A[correctPos]);
            i--;
        }
    }
}