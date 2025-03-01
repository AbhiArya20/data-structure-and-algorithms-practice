#include<bits/stdc++.h>
using namespace std;

// GFG - Lazy Propogation
// Update in range and query on one index
// Practice Link - https://nados.io/question/what-s-at-idx-point-query-range-update?zen=true
// What at index

class Solution{
    int n;
    vector<int> arr;
    vector<int> segmentTree;
    void buildSegment(int index, int start, int end){
        if(start == end){
            segmentTree[index] = arr[start];
            return;
        }
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;
        
        buildSegment(leftIndex, start, mid);
        buildSegment(rightIndex, mid+1, end);
    }
    void update(int index, int start, int end, int left, int right,int val){
        if(end<left || start>right)
            return;
        if(start>=left && end<=right){
            segmentTree[index] += val;
            return;
        }
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        update(leftIndex,start,mid,left,right,val);
        update(rightIndex,mid+1,end,left,right,val);
    }
    void propogation(int index, int leftIndex, int rightIndex){
        segmentTree[leftIndex]+=segmentTree[index];
        segmentTree[rightIndex]+=segmentTree[index];
        segmentTree[index] = 0;
    }
    int getAns(int index, int start, int end, int idx){
        if(start == end)
            return segmentTree[index];
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        propogation(index,leftIndex,rightIndex);

        if(idx<=mid)
            return getAns(leftIndex,start,mid,idx);
        return getAns(rightIndex,mid+1,end,idx);
    }
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    void update(int left, int right, int val){
        update(1,0,n-1,left,right,val);
    }
    int getAns(int idx){
        return getAns(1,0,n-1,idx);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i= 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Solution obj(arr);
    int queryLen;
    cin>>queryLen;
    for(int i = 0; i<queryLen; i++){
        int type;
        cin>>type;
        if(type == 0){
            int idx;
            cin>>idx;
            cout<<obj.getAns(idx)<<endl;
        }else{
            int left;
            int right;
            int val;
            cin>>left>>right>>val;
            obj.update(left, right, val);
        }
    }
}


// Pepcoding - Sum of Range Query and Range Update
// Practice Link - https://nados.io/question/sum-of-range-range-query-range-update?zen=true

class Solution1{
    int n;
    vector<int> arr;
    vector<int> segmentTree;
    vector<int> lazy;
    void buildSegment(int index, int start, int end){
        if(start == end){
            segmentTree[index] = arr[start];
            return;
        }
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;
        
        buildSegment(leftIndex, start, mid);
        buildSegment(rightIndex, mid+1, end);

        segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];
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
    void update(int index, int start, int end, int left, int right,int val){
        propogation(index,start,end);
        if(end<left || start>right)
            return;
        if(start>=left && end<=right){
            lazy[index] += val;

            propogation(index,start,end);
            
            return;
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;
        
        update(leftIndex,start,mid,left,right,val);
        update(rightIndex,mid+1,end,left,right,val);

        segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];
    }
    int getAns(int index, int start, int end, int left, int right){
        if(end<left || start>right)
            return 0;

        propogation(index,start,end);

        if(start>=left && end<=right){
            return segmentTree[index];
        }
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        int leftAns = getAns(leftIndex,start,mid,left,right);
        int rightAns = getAns(rightIndex,mid+1,end,left,right);

        return leftAns + rightAns;
    }
    public:
    Solution1(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        lazy.resize(4*n);
        buildSegment(1,0,n-1);
    }
    void update(int left, int right, int val){
        update(1,0,n-1,left,right,val);
    }
    int getAns(int left, int right){
        return getAns(1,0,n-1,left,right);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i= 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Solution1 obj(arr);
    int queryLen;
    cin>>queryLen;
    for(int i = 0; i<queryLen; i++){
        int type;
        cin>>type;
        if(type == 0){
            int left;
            int right;
            cin>>left>>right;
            cout<<obj.getAns(left,right)<<endl;
        }else{
            int left;
            int right;
            int val;
            cin>>left>>right>>val;
            obj.update(left, right, val);
        }
    }
}
