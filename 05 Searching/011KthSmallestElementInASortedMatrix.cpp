#include<bits/stdc++.h>
using namespace std;

// LeetCode - 378

class Solution { // The way i solved
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({matrix[0][0],0,0});
        set<pair<int,int>> st;
        st.insert({0,0});
        int curi = 0;
        int curj = 0;
        while(k){
            k--;
            while(!pq.empty() && st.find({curi,curj})!=st.end()){
                curi = pq.top()[1];
                curj = pq.top()[2];
                pq.pop();
            }
            st.insert({curi,curj});
            if(k==0)
                return matrix[curi][curj];
            if(curi+1<n){
                pq.push({matrix[curi+1][curj],curi+1,curj});
            }
            if(curj+1<n){
                pq.push({matrix[curi][curj+1],curi,curj+1});
            }  
        }
        return -1;
    }
};



class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int> maxHeap;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                maxHeap.push(matrix[r][c]);
                if (maxHeap.size() > k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        for (int r = 0; r < min(m, k); ++r)
            minHeap.push({matrix[r][0], r, 0});

        for (int i = 1; i <= k; ++i) {
            auto top = minHeap.top(); minHeap.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if (c + 1 < n) minHeap.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};



class Solution {
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1; 
            } else left = mid + 1;
        }
        return ans;
    }
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, c = n - 1;
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;
            cnt += (c + 1);
        }
        return cnt;
    }
};