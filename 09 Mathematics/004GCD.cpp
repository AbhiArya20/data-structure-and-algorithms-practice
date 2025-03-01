#include<bits/stdc++.h>
using namespace std;

// GFG - GCD of two numbers

class Solution{
	public:
    int gcd(int a, int b) { 
	    return b==0?a:gcd(b,a%b);
	} 
};

class Solution{
	public:
    int gcd(int a, int b) { 
	    while (b){
            a%=b;
            swap(a,b);
        }
        return a;
	} 
};



class Solution{
	public:
    int gcd(int a, int b) { 
        if(a==b)
            return a;
	    return a>b?gcd(a-b,b):gcd(a,b-a);
	} 
};


// Stein's Algorithms - for negative numbers gcd

class Solution{
    int gcd(int a, int b){
        if (a == b)
            return a;
        if (!a || !b)
            return b+a;
        if(!(a&1) && !(b&1))
            return gcd(a >> 1, b >> 1) << 1;
        if (!(a&1) && (b&1))
                return gcd(a >> 1, b);
        if ((a&1) && !(b&1))
            return gcd(a, b >> 1);
        if (a > b) // if both odd
            return gcd((a - b) >> 1, b);
        return gcd((b - a) >> 1, a);
    }
};


// GCD for one large and one is small number

typedef long long int ll;
class Solution{
    ll reduceB(ll a, string b){
        ll mod = 0;
        for (int i = 0; i < b.size(); i++)
            mod = (mod * 10 + b[i] - '0') % a;
        return mod;
    }
    ll gcdLarge(ll a, string b){
        ll num = reduceB(a, b);
        return __gcd(a, num);
    }
}

// some properties
// GCD(LCM (x, y), LCM (x, z)) = LCM(x, GCD(y, z))