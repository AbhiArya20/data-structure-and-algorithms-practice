#include<bits/stdc++.h>
using namespace std;

// LeetCode - 732

class MyCalendarThree {
    map<int,int> mp;
public:
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int count = 0;
        int ans = 0;
        for(auto pair: mp){
            count+=pair.second;
            ans = max(ans, count);
        }
        return ans;
    }
};