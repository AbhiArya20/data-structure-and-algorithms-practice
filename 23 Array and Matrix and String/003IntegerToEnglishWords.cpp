#include<bits/stdc++.h>
using namespace std;

// LeetCode - 273

class Solution {
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight","Nine", "Ten","Eleven", "Twelve","Thirteen", "Fourteen", "Fifteen", "Sixteen","Seventeen","Eighteen", "Nineteen"};
    vector<string> tens = {"","","Twenty ", "Thirty ", "Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
    vector<string> hundreds = {"","One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven Hundred ","Eight Hundred ","Nine Hundred "};
    string getString(int n, string delemeter){
       string ans = "";
       if(n>99){
           ans+= hundreds[n/100];
           if(n%100>19) 
                ans+=tens[(n/10)%10] + ones[n%10];
            else
                ans+=ones[n%100];
       }else if(n>19){
           ans+= tens[n/10] + ones[n%10];
       }else if(n){
           ans += ones[n];
       }
       if(n && delemeter!=""){
           if(ans[ans.size()-1] != ' ')
                ans += " " + delemeter;
            else
                ans += delemeter;
       }
       return ans;
    }
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string ans = "";
        ans+= getString(num/1000000000,"Billion ");
        ans+= getString((num%1000000000)/1000000,"Million ");
        ans+= getString((num%1000000)/1000,"Thousand ");
        ans+= getString((num%1000),"");
        if(ans[ans.size()-1] == ' ')
            ans.pop_back();
        return ans;
    }
};