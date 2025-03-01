#include<bits/stdc++.h>
using namespace std;

// GFG - Get minimum element from stack


class Solution{
    int minEle;
    stack<int> s,m;
    public:
       int getMin(){
           if(s.size()==0)
                return -1;
           return m.top();
       }
       int pop(){
           if(s.size()==0)
                return -1;
           int val = s.top();
           s.pop();
           if(val<=m.top())
                m.pop();
           return val;
       }
       void push(int x){
            if(s.size()==0){
                s.push(x);
                m.push(x);
                return;
            }
            if(m.top() >= x)
                m.push(x);
            s.push(x);
       }
};


class Solution{
    int minEle;
    stack<int> s;
    public:
       int getMin(){
           if(s.size()==0)
                return -1;
           return minEle;
       }
       int pop(){
            if(s.size()==0)
                return -1;
            int val = s.top();
            s.pop();
            if(val>=minEle){
                return val;
            }
            int val2 = minEle;
            minEle = 2*minEle-val;
            return val2;
       }
       void push(int x){
           if(s.size()==0){
               minEle =x;
               s.push(x);
               return;
           }
           if(x>=minEle){
                s.push(x);
                return;
           }
           s.push(x*2-minEle);
           minEle = x;
       }
};
