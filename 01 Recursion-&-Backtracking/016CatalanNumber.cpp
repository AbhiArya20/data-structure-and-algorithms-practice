#include<bits/stdc++.h>
using namespace std;

// GFG - Catalan Number

int catalanNumber(int n){
        if(n<=1)
            return 1;
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans+=catalanNumber(i)*catalanNumber(n-i-1);
        }
        return ans;
}