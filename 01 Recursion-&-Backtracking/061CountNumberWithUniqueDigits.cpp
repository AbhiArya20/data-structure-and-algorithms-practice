#include<bits/stdc++.h>
using namespace std;

// LeetCode - 357

class Solution {
    unordered_set<int> s;
    int getAll(int i, int size,int n){
        if(size == n){
            return 0;
        }
        int ans = 0;
        for(int j = 1; j<=9; j++){
            int val1 = ((i%10)+j);
            int val2 = ((i%10)-j);
            if(val1<=9){
                if(s.find(val1)==s.end()){
                    s.insert(val1);
                    ans += 1 + getAll(i*10+val1,size+1,n);
                    s.erase(val1);
                }
            }
            if(val2>=0){
                if(s.find(val2)==s.end()){
                    s.insert(val2);
                    ans += 1 + getAll(i*10+val2,size+1,n);
                    s.erase(val2);
                }
            }
        }
        return ans;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int ans = 10;
        for(int i = 1; i<=9; i++){
            s.insert(i);
            ans+=getAll(i,1,n);
            s.erase(i);
        }
        return ans;
    }
};