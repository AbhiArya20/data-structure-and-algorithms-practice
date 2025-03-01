#include<bits/stdc++.h>
using namespace std;

// GFG - Sort a Stack

void sortAStack(stack<int> s)
{
   if(s.empty()){
       return;
   }
   int temp = s.top();
   s.pop();
   sortAStack(s);
   stack<int> st; // we can use another recursive fuction at place of stack
   while(!s.empty() && s.top()>temp){
       st.push(s.top());
       s.pop();
   }
   s.push(temp);
   while(!st.empty()){
       s.push(st.top());
       st.pop();
   }
}