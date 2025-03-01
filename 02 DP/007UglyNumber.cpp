#include<bits/stdc++.h>
using namespace std;

// LeetCode - 264

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        vector<int> factors(3);
        vector<int> pointers(3);
        factors[0]=2;
        factors[1]=3;
        factors[2]=5;
        ugly[0]=1;
        int ans = 1;
        for(int i = 1; i<n; i++){
            priority_queue<int,vector<int> ,greater<int>> pq; // we can eleminate this by minimizing our val in below
            for(int i = 0; i<3; i++){
                int val = ugly[pointers[i]]*factors[i];
                pq.push(val);
            }
            ans = pq.top();
            ugly[i]=ans;
            for(int i = 0; i<3; i++){
                int val = ugly[pointers[i]]*factors[i];
                if(val==ans){
                    pointers[i]++;
                }
            }
        }
        return ans;
    }
};




// LeetCode - 313

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) { // either test case were change or wrong problem description(guaranteed to fit in a 32-bit signed integer)
        vector<int> ugly(n);
        int m = primes.size();
        vector<int> pointers(m);
        ugly[0]=1;
        int ans = 1;
        for(int i = 1; i<n; i++){
            int mini = INT_MAX;
            for(int i = 0; i<m; i++){
                int val = ugly[pointers[i]]*primes[i];
                mini = min(mini, val);
            }
            ans = mini;
            ugly[i]=ans;
            for(int i = 0; i<m; i++){
                int val = ugly[pointers[i]]*primes[i];
                if(val==ans){
                    pointers[i]++;
                }
            }
        }
        return ans;
    }
};