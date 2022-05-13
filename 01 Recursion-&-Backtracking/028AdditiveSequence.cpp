#include<bits/stdc++.h>
using namespace std;

// GFG - Additive Sequence
// GFG - Sum-String
// LeetCode - 306



bool isValid(string str){
    if(str.size()>1 && str[0]=='0')
        return false;
    return true;
}
int valueofchar(string str, int pos){
    if(pos<0)
        return 0;
    return (str[pos]-'0');
}
string getSum(string str1,string str2){
    string sum = "";
    int carry = 0;
    int i = str1.size()-1;
    int j = str2.size()-1;
    while(i>=0 || j>=0){
        int sm = valueofchar(str1,i)+valueofchar(str2,j)+carry;
        sum+=(sm%10+'0');
        carry = sm/10;
        i--;
        j--;
    }
    if(carry){
        sum+=(carry+'0');
    }
    reverse(sum.begin(),sum.end());
    return sum;
}
bool isAdditive(string secPrev, string prev, string rest){
    if(!isValid(secPrev) || !isValid(prev))
        return false;
    string sum = getSum(secPrev, prev);
    if(rest == sum)
        return true;
    if(rest.size()<=sum.size() || sum!=rest.substr(0,sum.size()))
        return false;
    return isAdditive(prev,sum,rest.substr(sum.size()));
}
bool isAdditiveSequence(string s)
{
    int n = s.size();
    for(int i = 1; i<=n/2; i++){
        for(int j = 1; j<=(n-i)/2; j++){
            if(isAdditive(s.substr(0,i),s.substr(i,j),s.substr(i+j))){
                return true;
            }
        }
    }
    return false;
}