#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2514

class Solution {
    int mod = 1e9+7;
    vector<int> fact;
    long long power(int n, int m){
        if(m==0)
            return 1;
        long long temp = power(n,m/2);
        temp  = (temp*temp)%mod;
        if(m%2)
            temp = (temp*n)%mod;
        return temp;
    }
public:
    int countAnagrams(string s) {
        int n = s.size();
        fact.push_back(0);
        long long prod = 1;
        for(int i = 1; i<=n; i++){
            prod  = (prod*i)%mod;
            fact.push_back(prod);
        }
        unordered_map<char,int> um;
        long long ans = 1;
        for(int i = 0; i<n; i++){
            if(s[i]==' '){
                long long dem = 1;
                long long count = 0;
                for(auto v: um){
                    count+=v.second;
                    dem *= fact[v.second];
                    dem %= mod;
                }
                long long num = fact[count];
                ans *= (num * power(dem, mod - 2))%mod;
                ans %= mod;
                um.clear();
            }else{
                um[s[i]]++;
            }
        }
        if(um.size()){
            long long dem = 1;
            long long count = 0;
            for(auto v: um){
                count+=v.second;
                dem *= fact[v.second];
                dem %= mod;
            }
            long long num = fact[count];
            ans *= (num * power(dem, mod - 2))%mod;
            ans %= mod;
            um.clear();
        }
        return ans;
    }
};