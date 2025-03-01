#include<bits/stdc++.h>
using namespace std;

// GFG - Range Sum and Update in Array : Segment Tree using Stack

class Solution{
    const int INF = 1e9;
    class DataValues{
        public:
        int index;
        int start; 
        int end;
        DataValues(int index, int start, int end){
            this->index = index;
            this->start = start;
            this->end = end;
        }
    };
    vector<int> segmentTree,lazy,arr;
    int n;
    void build(){
        stack<DataValues*> st;
        st.push(new DataValues(1,0,n-1));
        while (!st.empty()){
            int index = st.top()->index;
            int start = st.top()->start;
            int end = st.top()->end;
            st.pop();

            int leftIndex = index*2;
            int rightIndex = index*2+1;
            if(start == INF && end == INF){
                segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];
            }
            else if(start == end){
                segmentTree[index] = arr[start];
            }else{
                st.push(new DataValues(index,INF,INF));
                int mid = (start+end)>>1;
                st.push(new DataValues(leftIndex,start,mid));
                st.push(new DataValues(rightIndex,mid+1,end));
            }
        }    
    }
    void propogation(int index, int start, int end){
        int totalVal = (end-start+1)*lazy[index];
        segmentTree[index] += totalVal;
        if(start != end){
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;
            lazy[leftIndex]+=lazy[index];
            lazy[rightIndex]+=lazy[index];
        }
        lazy[index] = 0;
    }
    void updateSegment(int left,int right, int val){
        stack<DataValues*> st;
        st.push(new DataValues(1,0,n-1));
        while (!st.empty()){
            int index = st.top()->index;
            int start = st.top()->start;
            int end = st.top()->end;
            st.pop();

            int leftIndex = index*2;
            int rightIndex = index*2+1;
            if(start == INF && end == INF){
                segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];
            }
            else{
                propogation(index, start, end);
                if(start>end || end<left || start>right)
                    continue;
                else if(start>=left && end<=right){
                    lazy[index]+=val;
                    propogation(index,start,end);
                }
                else{
                    st.push(new DataValues(index,INF,INF));
                    int mid = (start+end)>>1;
                    st.push(new DataValues(leftIndex,start,mid));
                    st.push(new DataValues(rightIndex,mid+1,end));
                }
            }
        }    
    }
    int getAns(int left, int right){
        int ans = 0;
        stack<DataValues*> st;
        st.push(new DataValues(1,0,n-1));
        while (!st.empty()){
            int index = st.top()->index;
            int start = st.top()->start;
            int end = st.top()->end;
            st.pop();
            propogation(index,start,end);
            int leftIndex = index*2;
            int rightIndex = index*2+1;
            if(start>end || end<left || start>right)
                continue;
            else if(start>=left && end<=right){
                ans += segmentTree[index];
            }
            else if(start == end){
                segmentTree[index] = arr[start];
            }else{
                int mid = (start+end)>>1;
                st.push(new DataValues(leftIndex,start,mid));
                st.push(new DataValues(rightIndex,mid+1,end));
            }
        }  
        return ans;  
    }
    public:
    Solution(vector<int> &arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        lazy.resize(4*n);
        build();
    }
    void update(int left, int right, int val){
        updateSegment(left, right, val);
    }
    int getSum(int left, int right){
        return getAns(left, right);
    }
};