#include<bits/stdc++.h>
using namespace std;

// GFG - Segment Tree - Maximum in Range
// Practice Link - https://nados.io/question/max-in-a-interval-range-query-point-update?zen=true

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

        segmentTree[index] = max(segmentTree[leftIndex], segmentTree[rightIndex]);
    }
    int getMaxFromSegment(int index, int start, int end, int left,int right){
        if(end<left || start>right)
            return INT_MIN;
        if(start >= left && end<=right){    
            return segmentTree[index];
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        int leftAns = getMaxFromSegment(leftIndex, start, mid, left, right);
        int rightAns = getMaxFromSegment(rightIndex, mid+1, end, left, right);

        return max(leftAns, rightAns);
    }
    void updateSegment(int index, int start, int end, int indexWhereUpdate, int val){
        if(start == end){
            arr[indexWhereUpdate] = val;
            segmentTree[index] = val;
            return;
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        if(indexWhereUpdate <= mid)
            updateSegment(leftIndex,start,mid,indexWhereUpdate,val);
        else
            updateSegment(rightIndex,mid+1,end,indexWhereUpdate,val);

        segmentTree[index] = max(segmentTree[leftIndex], segmentTree[rightIndex]);

    }
    public:    
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    int getMax(int left, int right){
        return getMaxFromSegment(1,0,n-1,left,right);
    }
    void update(int index, int val){
        updateSegment(1,0,n-1,index,val);
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
            int index;
            int val;
            cin>>index>>val;
            obj.update(index, val);
        }else{
            int left;
            int right;
            cin>>left>>right;
            cout<<obj.getMax(left, right)<<endl;
        }
    }    
}



// Minimum in Range

class Solution1{
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

        segmentTree[index] = min(segmentTree[leftIndex], segmentTree[rightIndex]);
    }
    int getMinFromSegment(int index, int start, int end, int left,int right){
        if(end<left || start>right)
            return INT_MAX;
        if(start >= left && end<=right){    
            return segmentTree[index];
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        int leftAns = getMinFromSegment(leftIndex, start, mid, left, right);
        int rightAns = getMinFromSegment(rightIndex, mid+1, end, left, right);

        return min(leftAns, rightAns);
    }
    void updateSegment(int index, int start, int end, int indexWhereUpdate, int val){
        if(start == end){
            arr[indexWhereUpdate] = val;
            segmentTree[index] = val;
            return;
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        if(start <= indexWhereUpdate && indexWhereUpdate <= mid)
            updateSegment(leftIndex,start,mid,indexWhereUpdate,val);
        else
            updateSegment(rightIndex,mid+1,end,indexWhereUpdate,val);

        segmentTree[index] = min(segmentTree[leftIndex], segmentTree[rightIndex]);

    }
    public:    
    Solution1(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    int getMin(int left, int right){
        return getMinFromSegment(1,0,n-1,left,right);
    }
    void update(int index, int val){
        updateSegment(1,0,n-1,index,val);
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
            int index;
            int val;
            cin>>index>>val;
            obj.update(index, val);
        }else{
            int left;
            int right;
            cin>>left>>right;
            cout<<obj.getMin(left, right)<<endl;
        }
    }    
}



