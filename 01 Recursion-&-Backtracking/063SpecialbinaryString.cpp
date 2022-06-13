#include<bits/stdc++.h>
using namespace std;

// LeetCode - 761


class Solution {
    void getAns(string s, string &ans){
        ans = max(ans, s);
        int n = s.size();
        for(int start = 0; start<n; start++){
            int o = 0, z = 0;
            for(int end = start; end <n; end++){
                if(s[end] == '1')
                    o++;
                else
                    z++;
                if(z>o)
                    break;
                if(z==o){
                    int o2 = 0, z2 = 0;
                    for(int end2 = end+1; end2<n; end2++){
                        if(s[end2] == '1')
                            o2++;
                        else
                            z2++;
                        if(z2==o2){
                            string first = s.substr(start, end2-start+1);
                            string second = s.substr(end+1,end2-end)+s.substr(start,end-start+1);
                            if(first<second){
                                for(int k = 0; k<second.size(); k++){
                                    s[start+k] = second[k];
                                } 
                                getAns(s,ans);            
                                goto next;
                            }
                        }
                    }
                }
            }
            next:;
        }
    }
public:
    string makeLargestSpecial(string s) {
        string ans = s;
        getAns(s,ans);
        return ans;
    }
};

class Solution { // Iterative version of above code and accepted
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        bool change = true;
        while(change){
            change = false;
            for(int start = 0; start<n; start++){
                int o = 0, z = 0;
                for(int end = start; end <n; end++){
                    if(s[end] == '1')
                        o++;
                    else
                        z++;
                    if(z>o)
                        break;
                    if(z==o){
                        int o2 = 0, z2 = 0;
                        for(int end2 = end+1; end2<n; end2++){
                            if(s[end2] == '1')
                                o2++;
                            else
                                z2++;
                            if(z2==o2){
                                string first = s.substr(start, end2-start+1);
                                string second = s.substr(end+1,end2-end)+s.substr(start,end-start+1);
                                if(first<second){
                                    for(int k = 0; k<second.size(); k++){
                                        s[start+k] = second[k];
                                    }             
                                    change = true;
                                    goto next;
                                }
                            }
                        }
                    }
                }
                next:;
            }
        }
        return s;
    }
};



class Solution { // optimized but did not understand how it works
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int i = 0, level = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') level++;
            else level--;
            if (level == 0) {
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - (i + 1))) + '0');
                i = j + 1;
            }
            
        }

        sort(res.begin(), res.end(), greater<string>());
        string ret = "";
        for (string& s : res) {
            ret += s;
        }

        return ret;
    }
};