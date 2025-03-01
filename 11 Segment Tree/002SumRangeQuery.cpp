#include<bits/stdc++.h>
using namespace std;

// GFG - Sum of Query II
// Practice Link - https://nados.io/question/sum-of-interval?zen=true
// LeetCode - 307

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

        segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];
    }
    int sumInRange(int index, int start, int end, int left,int right){
        if(end<left || start>right)
            return 0;
        if(start >= left && end<=right){    
            return segmentTree[index];
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        int leftAns = sumInRange(leftIndex, start, mid, left, right);
        int rightAns = sumInRange(rightIndex, mid+1, end, left, right);

        return leftAns+rightAns;
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

        segmentTree[index] = segmentTree[leftIndex]+segmentTree[rightIndex];

    }
    public:    
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    int sumInRange(int left, int right){
        return sumInRange(1,0,n-1,left,right);
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
            cout<<obj.sumInRange(left, right)<<endl;
        }
    }    
}




