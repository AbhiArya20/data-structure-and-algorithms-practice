#include<bits/stdc++.h>
using namespace std;

// GFG - Number Of Factor

class Solution{
   int countFactors(int n){
        int count = 0;
        for(int i = 1; i<=sqrt(n); i++){
            if(n%i==0){
                if(n/i == i){
                    count++;
                }
                else  { 
                    count+=2;
                }
            }
        }
        return count;
    }
};
// to print 
class Solution{
   void printFactor(int n){
        for(int i = 1; i<=sqrt(n); i++){
            if(n%i==0){
                if(n/i == i){ // last condition if i == sqrt(n)
                    cout<<i<<endl; 
                }
                else  { 
                    cout<<i<<" "<<n/i<<" ";
                }
            }
        }
    }
};



// GFG - 3 Divisors
class Solution{
    vector<int> threeDivisors(vector<long long> query, int q){
        vector<int> ans;
        for(auto n:query){
            int count = 0;
            for(int i = 1; i<=sqrt(n); i++){
                if(n%i==0){
                    if(n/i == i){
                        count++;
                    }
                    else  { 
                        count+=2;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};