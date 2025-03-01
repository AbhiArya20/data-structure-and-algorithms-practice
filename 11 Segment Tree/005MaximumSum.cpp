#include<bits/stdc++.h>
using namespace std;

// Practice Link - https://nados.io/question/maximum-sum?zen=true

class Solution1{
    int n;
    vector<int> arr;
    vector<pair<int,int>> segmentTree;
    pair<int,int> updateAns(pair<int,int> left, pair<int,int> right){
        int sum = max(left.first,right.first);
        sum = max(sum,left.second+right.second);
        int maxi = max(left.second,right.second);
        return {sum, maxi};
    }
    void buildSegment(int index, int start, int end){
        if(start == end){
            segmentTree[index] = {arr[start],arr[start]};
            return;
        }

        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        buildSegment(leftIndex, start, mid);
        buildSegment(rightIndex, mid+1, end);

        segmentTree[index] = updateAns(segmentTree[leftIndex],segmentTree[rightIndex]);
    }
    pair<int,int> getAns(int index, int start, int end, int left,int right){
        if(end<left || start>right)
            return {0,0};
        if(start >= left && end<=right){    
            return segmentTree[index];
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        auto leftAns = getAns(leftIndex, start, mid, left, right);
        auto rightAns = getAns(rightIndex, mid+1, end, left, right);

        return updateAns(leftAns,rightAns);
    }
    void updateSegment(int index, int start, int end, int indexWhereUpdate, int val){
        if(start == end){
            arr[indexWhereUpdate] = val;
            segmentTree[index] = {val,val};
            return;
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        if(start <= indexWhereUpdate && indexWhereUpdate <= mid)
            updateSegment(leftIndex,start,mid,indexWhereUpdate,val);
        else
            updateSegment(rightIndex,mid+1,end,indexWhereUpdate,val);

        segmentTree[index] = updateAns(segmentTree[leftIndex],segmentTree[rightIndex]);

    }
    public:    
    Solution1(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    int getAns(int left, int right){
        return getAns(1,0,n-1,left,right).first;
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
            cout<<obj.getAns(left, right)<<endl;
        }
    }    
}