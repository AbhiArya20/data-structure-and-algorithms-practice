#include<bits/stdc++.h>
using namespace std;


class Solution{
    int powr(int n){
        int val = 1;
        while((val<<1)<=n)
            val = (val<<1);
        return val;
    }
public:
    int find(int N){
        int l = N-powr(N);
        return 2*l+1;
    }
};
