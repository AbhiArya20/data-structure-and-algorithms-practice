#include<bits/stdc++.h>
using namespace std;

// LeetCode - 149
// GFG - Hit Most Ballons

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            map<pair<int,int>,int> um;
            int overlap = 0;
            int maxi = 0;
            for(int j = i+1; j<n; j++){
                if(points[i]==points[j])
                    overlap++;
                else{
                    int ydif = points[j][1] - points[i][1];
                    int xdif = points[j][0] - points[i][0];
                    int gcd = __gcd(ydif,xdif);
                    ydif/=gcd;
                    xdif/=gcd;
                    um[{ydif,xdif}]++;
                    maxi = max(maxi,um[{ydif,xdif}]);
                }
            }
            ans = max(ans, maxi+overlap+1);
        }
        return ans;
    }
};