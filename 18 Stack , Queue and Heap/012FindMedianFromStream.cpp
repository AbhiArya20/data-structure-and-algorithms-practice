#include<bits/stdc++.h>
using namespace std;

// LeetCode - 295
// GFG - Find median in a stream


class MedianFinder {
    multiset<int> st;
    multiset<int>:: iterator it;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        auto it2 = st.insert(num);
        int n = st.size();
        if(n==1){
            it = st.begin();
            return;
        }
        if(num>=*it){
            if(n%2==0)
                it++;
        }else{
            if(n%2)
                it--;
        }
    }
    
    double findMedian() {
        int n = st.size();
        if(n&1)
            return *it;
        int val1 = *it;
        it--;
        int val2 = *it;
        it++;
        return ((double)(val1)+(double)(val2))/2;
    }
};