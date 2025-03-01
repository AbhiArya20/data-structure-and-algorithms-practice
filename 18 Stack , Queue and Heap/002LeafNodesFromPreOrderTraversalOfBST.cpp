#include<bits/stdc++.h>
using namespace std;

// GFG - Print leaf nodes from preorder traversal of BST

class Solution {
  public:
    vector<int> leafNodes(int arr[],int n) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i<n; i++){
            int count = 0;
            int temp = -1;
            while(!st.empty() && st.top()<arr[i]){
                if(temp == -1){
                    temp = st.top();
                }
                st.pop();
                count++;
            }
            if(count >= 2)
                ans.push_back(temp);
            st.push(arr[i]);
        }
        if(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};