#include<bits/stdc++.h>
using namespace std;

// GFG - Reverse Stack


class Solution{
    void  Reverse(stack<int> &St, int g){
        if(St.empty()){
            St.push(g);
            return;
        }
        int t = St.top();
        St.pop();
        Reverse(St, g);
        St.push(t);
    }
public:
    void Reverse(stack<int> &St){
        if(St.empty())
            return;
        int t = St.top();
        St.pop();
        Reverse(St);
        Reverse(St, t);
    }
};