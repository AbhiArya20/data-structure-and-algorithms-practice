#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Multiplications to reach End

class Solution {
    int mod = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        vector<int> vis(100001, -1);
        queue<int> q;
        q.push(start % mod);
        vis[start] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top == end)
                return vis[end];
            for (int i = 0; i < n; i++) {
                int pushed = top * arr[i];
                pushed = pushed % mod;
                if (vis[pushed] == -1) {
                    vis[pushed] = vis[top] + 1;
                    q.push(pushed);
                }
            }
        }
        return -1;
    }
};