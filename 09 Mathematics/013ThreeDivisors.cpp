#include<bits/stdc++.h>
using namespace std;

// GFG - 3Divisors


bool flag = false;
vector<bool> prime(1000000+5,true); // cheated by making global variable
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q){
        if(flag == false){
            flag = true;
            prime[1]=false;
            prime[0]=false;
            for(int i = 2; i*i<=1000000+5; i++){
                if(prime[i]==true){
                    for(int j = i*i; j<=1000000+5; j+=i){
                        prime[j] = false;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<q; i++){
            long long n = query[i];
            int count = 0;
            for(long long i = 2; i*i<=n; i++){
                if(prime[i]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
