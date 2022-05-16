#include<bits/stdc++.h>
using namespace std;

// LeetCode - 17

class Solution {
    unordered_map<char,string> um;
    void combination(int index,string digits, string st, vector<string> &ans){
        if(index== digits.size()){
            ans.push_back(st);
            return;
        }
        for(auto c: um[digits[index]]){
            combination(index+1,digits,st+c,ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        vector<string> ans;
        string st = "";
        um.insert({'2',"abc"});
        um.insert({'3',"def"});
        um.insert({'4',"ghi"});
        um.insert({'5',"jkl"});
        um.insert({'6',"mno"});
        um.insert({'7',"pqrs"});
        um.insert({'8',"tuv"});
        um.insert({'9',"wxyz"});
        combination(0,digits, st, ans);
        return ans;
    }
};