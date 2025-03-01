#include<bits/stdc++.h>
using namespace std;

// LeetCode - 218

class Solution { // Line Sweeping that I got
    struct Event{
        int index;
        int line;
        int height;
        bool left;
        Event(int idx, int ln, int hgt, bool lt){
            index = idx;
            line = ln;
            height = hgt;
            left = lt;
        }
        bool operator<(const Event& e) const {
                if(height==e.height)return line>e.line;
                return height > e.height;
        }
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<Event> arr;
        vector<int> prev = {-1,-1,-1};
        for(int i = 0; i<n; i++){
            if(prev == buildings[i])
                continue;
            arr.push_back(Event(i,buildings[i][0],buildings[i][2],true));
            arr.push_back(Event(i,buildings[i][1],buildings[i][2],false));
            prev = buildings[i];
        }
        sort(arr.begin(),arr.end(),[](Event a, Event b){
            if(a.line == b.line){
                if(a.left && b.left)
                    return a.height>b.height;
                if(!a.left && !b.left){
                    return a.height<b.height;
                }
                return a.left;
            }
            return a.line<b.line;
        });
        vector<vector<int>> ans;
        set<Event> st;
        for(int i = 0; i<arr.size(); i++){
            Event cur = arr[i];
            if(cur.left){
                if(st.empty() || (*st.begin()).height < cur.height){
                    ans.push_back({cur.line, cur.height});
                }
                st.insert(cur);
            }else{
                auto it = st.find(Event(cur.index,buildings[cur.index][0],cur.height,true));
                st.erase(it);
                if(st.empty()){
                    ans.push_back({cur.line,0});
                }else if(cur.height>(*st.begin()).height){
                    ans.push_back({cur.line,(*st.begin()).height});
                }
            }
        }
        return ans;
    }
};


class Solution { // Easy to understand
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> arr,ans;
        for(int i = 0; i<n; i++){
            arr.push_back({buildings[i][0],-1*buildings[i][2]});
            arr.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(arr.begin(),arr.end());
        multiset<int> st;
        st.insert(0);
        int prev = 0;
        for(int i = 0; i<2*n; i++){
            if(arr[i][1]<0){
                st.insert(-1*arr[i][1]);
            }else{
                st.erase(st.find(arr[i][1]));
            }
            int cur = *st.rbegin();
            if(prev != cur){
                ans.push_back({arr[i][0],cur});
                prev = cur;
            }
        }
        return ans;
    }
};