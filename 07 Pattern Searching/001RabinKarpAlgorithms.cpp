#include<bits/stdc++.h>
using namespace std;

// GFG - Rabin Karp Algorithm
// GFG - Search Pattern (Rabin-Karp Algorithm)

/*
    Idea is to calculate hash(s[i+1,i+m]) from hash(s[i,i+m-1]) and hash(s[i,i+m])

    hash(s[i+1,i+m]) = d*(hash(s[i,i+m-1]) - s[i]*h + s[i+m]) % mod

    s = text
    m = length(patter)
    mod = prime 
    d = numberOfCharacter
    h = pow(d,m-1)%q
*/

class Solution{
    const int d = 256;
    const int q = INT_MAX;
    int initialHash(string &s, int m){
        int hash = 0;
        for(int i = 0; i<m; i++)
            hash = (d*hash+s[i])%q;
        return hash;
    }
    int nextHash(int curHash,int idx, string &s, int h, int m){
        curHash = (d*(curHash-s[idx]*h) + s[idx+m])%q;
        if(curHash<0)
            curHash += q;
        return curHash;
    }
    int valueOfh(int m){
        int h = 1;
        for(int i = 0; i<m-1; i++){
            h = (h*d)%q;
        }
        return h;
    }
    public:
    vector <int> search(string &pat, string &txt){
        vector<int> ans;
        int n = txt.size();
        int m = pat.size();
        
        int h = valueOfh(m);
        int patternHash = initialHash(pat, m);
        int textHash = initialHash(txt,m);

        for (int i = 0; i <= n-m; i++){
            if(patternHash == textHash){
                int j = 0;
                for(; j<m; j++){
                    if(txt[i+j]!=pat[j]){
                        break;
                    }
                }
                if(j==m)
                    ans.push_back(i+1);
            }
            if(i<n-m)
                textHash = nextHash(textHash,i,txt,h,m);
        }
        if(ans.size()==0)
            ans.push_back(-1);
        return ans;
    }
};