#include<bits/stdc++.h>
using namespace std;

// GFG - Sieve of Eratosthenes

class Solution{
    public:
        vector<int> sieveOfEratosthenes(int N){
            vector<int> prime(N+1,true);
            prime[1]=false;
            prime[0]=false;
            for(int i = 2; i*i<=N; i++){
                if(prime[i]==true){
                    for(int j = i*i; j<=N; j+=i){
                        prime[j] = false;
                    }
                }
            }
            vector<int> ans;
            for(int i = 2; i<=N; i++){
                if(prime[i])
                    ans.push_back(i);
            }
            return ans;
        }
};




// Segmented Sieve
// Practice Link - https://nados.io/question/segmented-sieve?zen=true
class Solution{
    vector<int> sieveOfEratosthenes(int n){
        vector<int> ans;
        vector<int> isPrime(n+1,true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i<=n; i++){
            if(isPrime[i]){
                ans.push_back(i);
                for(int j = i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
    public:
    vector<int> segmentedSeive(int left, int right){
        auto primes = sieveOfEratosthenes(sqrt(right));
        int sizeOfdummy = right-left+1;
        vector<int> dummy(sizeOfdummy,true);
        for(auto prime: primes){
            int first = (left/prime)*prime;
            if(first<left)
                first+=prime;
            for(int i = max(prime*prime,first); i<=right; i+=prime){
                dummy[i-left]=false;
            }
        }
        if(left == 1)
          dummy[0]=false;
        vector<int> ans;
        for(int i=left; i<=right;i++){
            if(dummy[i-left])
                ans.push_back(i);
        }
        return ans;
    }
};


// Linear Seive
class Solution{
    vector<int> linearSieve(int n){
        vector<int> minimumFactor(n+1),prime;
        for(int i = 2; i<=n; i++){
            if(minimumFactor[i]==0){
                minimumFactor[i] = i;
                prime.push_back(i);
            }
            for(int j = 0; i*prime[j]<=n; j++){
                minimumFactor[i*prime[j]] = i;
                if(prime[j]==minimumFactor[i])
                    break;
            }
        }
        return prime;
    }
};