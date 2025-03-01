#include<bits/stdc++.h>
using namespace std;

// GFG - Tower Of Hanoi

class Solution{
    long long ans = 0;
    void T(int n, int f, int t, int a){
        if(n==0)
            return;
        ans++;
        T(n-1, f, a, t);
        cout<<"move disk "<<(n)<<" from rod "<<f<<" to rod "<<t<<endl;
        T(n-1, a,t,f);
    }
    public:
    long long toh(int N, int from, int to, int aux) {
        T(N, from, to, aux);
        return ans;
    }
};