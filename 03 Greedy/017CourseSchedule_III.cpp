#include<bits/stdc++.h>
using namespace std;

// LeetCode - 630

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),[](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        priority_queue<int> pq;
        int n = courses.size();
        int ans = 0;
        int end = 0;
        for(int i = 0; i<n; i++){
            if(courses[i][0]+end>courses[i][1]){
                if(!pq.empty() && courses[i][0]<pq.top()){
                    end-=pq.top();
                    pq.pop();
                    end+=courses[i][0];
                    pq.push(courses[i][0]);
                }
            }else{
                ans++;
                end+=courses[i][0];
                pq.push(courses[i][0]);
            }
        }
        return ans;
    }
};