#include<bits/stdc++.h>
using namespace std;

// GFG - AtoI

class Solution{
    int stoii(int i, string str, int ans){
        if(i==str.size()){
            return ans;
        }
        if(str[i]>='0' && str[i]<='9'){
            return stoii(i+1,str,ans*10+(str[i]-'0'));    
        }
        return -1;
    }
  public:
    int atoi(string str) {
        return str[0] == '-' && (str.size()>=2 && str[1]>='0' && str[1]<='9') ? stoii(0,str.substr(1), 0)*-1:stoii(0,str, 0); 
    }
};