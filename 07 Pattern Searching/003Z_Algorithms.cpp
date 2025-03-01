#include<bits/stdc++.h>
using namespace std;

// GFG - Z Algorithm

class Solution{
    vector<int> getZarray(string st){
        int n = st.size();
        vector<int> zArray(n);
        int left = 0;
        int right = 0;
        int k;
        for(int i = 1; i<n; i++){
            if(i>right){
                left = right = i;
                while(right<n && st[right-left] == st[right])
                    right++;
                zArray[i] = right-left;
                right--;
            }else{
                k = i-left;
                if(zArray[k]<right-i-1){
                    zArray[i] = zArray[k];
                }else{
                    left = i;
                    while(right<n && st[right-left] == st[right])
                        right++;
                    zArray[i] = right-left;
                    right--;
                }
            }
        }
        return zArray;
    }
    public:
        vector <int> search(string pat, string txt){
            int m = pat.size();
            int n = txt.size();
            string zString = pat+"$"+txt;
            vector<int> zArray = getZarray(zString);
            vector<int> ans;
            for(int i = 0; i<n+m+1; i++)
                if(zArray[i] == m)
                    ans.push_back(i-m);
            return ans; 
        }
};