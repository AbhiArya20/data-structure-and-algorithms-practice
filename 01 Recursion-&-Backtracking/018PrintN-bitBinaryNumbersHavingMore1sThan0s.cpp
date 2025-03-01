#include<bits/stdc++.h>
using namespace std;


//GFG - Print N-bit binary numbers having more 1s than 0s

class Solution{
    void allPos(int i, int n, int o,int z, string st, vector<string> & ans){
        if(i==n){
            ans.push_back(st);
            return;
        }
        allPos(i+1,n, o+1, z,st+"1",ans);
        if(z<o){
            allPos(i+1,n ,o, z+1, st+"0",ans);
        }
    }
public:	
	vector<string> NBitBinary(int n){
	    vector<string> ans;
	    allPos(1,n, 1, 0, "1", ans);
	    return ans;
	}
};