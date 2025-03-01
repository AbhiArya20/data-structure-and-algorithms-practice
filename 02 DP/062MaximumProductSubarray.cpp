#include<bits/stdc++.h>
using namespace std;

// LeetCode - 152

class Solution{
public:
	long long maxProduct(vector<int> arr) {
        int n = arr.size();
	    long long ans = *max_element(arr.begin(),arr.end()) ,mini=1,maxi=1;
	    for(long long  v: arr){
	        if(v==0){
	            mini = 1;
	            maxi = 1;
                continue;
	        }
	        long long  newMini = mini*v;
	        long long  newMaxi = maxi*v;
	        ans = max(max(v,ans),max(newMaxi,newMini)); 
	        maxi = max(newMini,max(newMaxi,v));
	        mini = min(newMaxi,min(newMini,v));
	    }
	    return ans;
	}
};
