#include<bits/stdc++.h>
using namespace std;

// GGF - Fact Digit Sum 

class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    unordered_map<int,int> fact;
	    fact[1] = 1;
	    fact[2] = 2;
	    fact[3] = 6;
	    fact[4] = 24;
	    fact[5] = 120;
	    fact[6] = 720;
	    fact[7] = 5040;
	    fact[8] = 40320;
	    fact[9] = 362880;
	    vector<int> ans;
	    while(N){
	        for(int i = 9; i>=1; i--){
	            if(fact[i]>N)
	                continue;
	            ans.push_back(i);
	            N-=fact[i];
	            break;
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};