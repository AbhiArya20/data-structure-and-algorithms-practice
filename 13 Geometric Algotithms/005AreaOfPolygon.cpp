#include<bits/stdc++.h>
using namespace std;

// Practice link - https://cses.fi/problemset/result/5320193/

class Solution{
    public: 
    long long int getArea(vector<pair<long long int, long long int>> points){
        long long int ans = 0.0;
        long long int n = points.size();
        for(int i = 0; i<n;i++){
            long long int x1 = points[i].first;
            long long int y1 = points[i].second;
            long long int x2 = points[(i+1)%n].first;
            long long int y2 = points[(i+1)%n].second;
            ans += ((x1*y2)-(x2*y1));
        }
        return abs(ans);
    }
};
int main(){
    int n;
    cin>>n;
    vector<pair<long long int,long long int>> points;
    for(int i = 0; i<n; i++){
        long long int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    Solution obj;
    cout<<obj.getArea(points)<<endl;
}