#include<bits/stdc++.h>
using namespace std;

// GFG - Eular Totient - To find numbers of coprimes in between

class Solution{ // Brute-force
public:
    long long ETF(long long n){
        long long ans = 1;
        for(long long i = 2; i<n; i++){
            if(__gcd(i,n) == 1)
                ans++;
        }
        return ans;
    }
};


class Solution{
public:
    long long ETF(long long n){
        long long ans = n;
        for(long long i = 2; i*i<=n; i++){
            if(n%i == 0){
                ans -= ans/i;
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1)
            ans -= ans/n;
        return ans;
    }
};

/*
    n and m = prime number
    eular(n) == n-1
    eular(n*m) = eular(n)*eular(m) = (n-1)*(m-1)
    eular(pow(n,k)) = pow(n,k)-pow(n,k-1)

    GCD(n,k) == 1, where(k!=n)


    eular(a*b) = eular(a)*eular(b) // a and b is co-prime
    eular(a*b) = gcd(a,b)/eular(gcd(a,b)) // a and b is not co-prime
    
    pow(a,eular(b)) ≡ 1 (mod b) => pow(a,eular(b))%n = 1 if a and b is co-prime
    pow(a,b-1) ≡ 1 (mod b) if a and b is prime number

*/
