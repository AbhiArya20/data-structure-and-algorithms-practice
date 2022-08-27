#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1605

class Solution { // Passed - But too slow and difficult to understand
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n,vector<int>(m));
        int isSum = true;
        while(isSum){
            isSum = false;
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            for(int i = 0; i<n; i++){
                if(rowSum[i]==0)
                    continue;
                pq.push({rowSum[i],{i,1}});
            }
            for(int i = 0; i<m; i++){
                if(colSum[i]==0)
                    continue;
                pq.push({colSum[i],{i,0}});
            }
            if(pq.size()){
                auto top = pq.top();
                int isRowOrCol = top.second.second;
                isSum = true;
                if(isRowOrCol){
                    for(int i = 0; i<m; i++){
                        if(colSum[i]>=top.first){
                            ans[top.second.first][i] = top.first;
                            rowSum[top.second.first] -= top.first;
                            colSum[i] -= top.first;
                            break;
                        }
                    }
                }else{
                    for(int i = 0; i<n; i++){
                        if(rowSum[i]>=top.first){
                            ans[i][top.second.first] = top.first;
                            colSum[top.second.first] -= top.first;
                            rowSum[i] -= top.first;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};



class Solution { // Optimal Solution
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> row;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> col;
        for(int i = 0; i<n; i++)
            row.push({rowSum[i],i});
        for(int i = 0; i<m; i++)
            col.push({colSum[i], i});
        while(!row.empty() && !col.empty()){
            auto p = row.top();
            auto p1 = col.top();
            row.pop();
            col.pop();
            if(p.first<=p1.first){
                ans[p.second][p1.second] = p.first;
                p1.first -= p.first;
                col.push({p1.first, p1.second});
            }else{
                ans[p.second][p1.second] = p1.first;
                p.first -= p1.first;
                row.push({p.first, p.second});
            }
        }
        return ans;   
    }
};