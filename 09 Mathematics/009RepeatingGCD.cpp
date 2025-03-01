#include<bits/stdc++.h>
using namespace std;

// GFG - Repeating GCD


class Solution{
    string repeating(long long int N, int gcd){
        string ans = "";
        for(int i = 0; i<gcd; i++){
            ans+=to_string(N);
        }
        return ans;
    }
	public:
	string FindGcd(long long int  N, int x, int y){
	    int gcd = __gcd(x,y);
	    return repeating(N,gcd);
	}
};