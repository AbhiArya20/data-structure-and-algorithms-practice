#include<bits/stdc++.h>
using namespace std;

// GFG - Possible Pair 

class Solution{
public:
    int pairCount(int x, int y){
        if(x==y)
            return 1;
        int n = x*y;
        int ans = 0;
        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                int a = i;
                int b = n/i;
                int gcd = __gcd(a,b);
                if(gcd==x && ((a*b)/gcd) == y)
                    ans++;
            }
        }
        return ans*2;
    }
};