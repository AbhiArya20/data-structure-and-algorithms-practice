#include<bits/stdc++.h>
using namespace std;

// GFG - Largest Prime Factor

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        if(N==1)
            return 1;
        long long int n = 2;
        while(N>1){
            if(N%n==0)
                N/=n;
            else
                n++;
        }
        return n;
    }
};


class Solution{ // Another Solution
public:
    long long largestPrimeFactor(long long n){
        long long ans = 0;
        for(long long i = 2; i*i<=n; i++){
            if(n%i == 0){
                ans++;
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1)
            ans++;
        return ans;
    }
};



class Solution{ // Using seive
        vector<int> sieveOfEratosthenes(int N){
            vector<int> prime(N+1);
            for(int i = 0; i<=N; i++)
                prime[i] = i;
            for(int i = 2; i*i<=N; i++){
                if(prime[i]==i){
                    for(int j = i*i; j<=N; j+=i){
                        if(prime[j] == j)
                            prime[j] = i;
                    }
                }
            }
            return prime;
        }
        vector<int> primeFactor(int n,vector<int> &prime){
            unordered_set<int> st; // you can avoid set if you need prime factor multiple time.
            vector<int> ans;
            while(n>1){
                if(st.find(prime[n])==st.end())
                    ans.push_back(prime[n]);
                st.insert(prime[n]);
                n /= prime[n];
            }
            return ans;
        }
    public:
        vector<vector<int>> getPrimeFactor(vector<int> &arr){
            int maxi = *max_element(arr.begin(),arr.end());
            auto prime = sieveOfEratosthenes(maxi);
            vector<vector<int>> ans;
            for(auto v: arr)
                ans.push_back(primeFactor(v,prime));
            return ans;
        }
};

// Count of All Divisors
class Solution{ // Using seive
        vector<int> sieveOfEratosthenes(int N){
            vector<int> prime(N+1);
            for(int i = 0; i<=N; i++)
                prime[i] = i;
            for(int i = 2; i*i<=N; i++){
                if(prime[i]==i){
                    for(int j = i*i; j<=N; j+=i){
                        if(prime[j] == j)
                            prime[j] = i;
                    }
                }
            }
            return prime;
        }
        unordered_map<int,int> primeFactor(int n,vector<int> &prime){
            unordered_map<int,int> mp;
            while(n>1){
                mp[prime[n]]++;
                n /= prime[n];
            }
            return mp;
        }
    public:
        vector<int> getPrimeFactor(vector<int> &arr){
            int maxi = *max_element(arr.begin(),arr.end());
            auto prime = sieveOfEratosthenes(maxi);
            vector<int> ans;
            for(auto v: arr){
                auto mp = primeFactor(v,prime);
                int val = 1;
                for(auto p : mp){
                    val *= p.second+1;
                }
                ans.push_back(val);
            }
            return ans;
        }
};

// Sum of All Divisors

class Solution{ // Using seive
        vector<int> sieveOfEratosthenes(int N){
            vector<int> prime(N+1);
            for(int i = 0; i<=N; i++)
                prime[i] = i;
            for(int i = 2; i*i<=N; i++){
                if(prime[i]==i){
                    for(int j = i*i; j<=N; j+=i){
                        if(prime[j] == j)
                            prime[j] = i;
                    }
                }
            }
            return prime;
        }
        unordered_map<int,int> primeFactor(int n,vector<int> &prime){
            unordered_map<int,int> mp;
            while(n>1){
                mp[prime[n]]++;
                n /= prime[n];
            }
            return mp;
        }
    public:
        vector<int> getPrimeFactor(vector<int> &arr){
            int maxi = *max_element(arr.begin(),arr.end());
            auto prime = sieveOfEratosthenes(maxi);
            vector<int> ans;
            for(auto v: arr){
                auto mp = primeFactor(v,prime);
                int val = 1;
                for(auto p : mp){
                    val *= ((int)pow(p.first,p.second+1)-1)/(p.first-1);
                }
                ans.push_back(val); // (val-v) if you need sum of perfect divisors
            }
            return ans;
        }
};