#include<bits/stdc++.h>
using namespace std;

// GFG - Fenwick Tree Range Update and Range Query


class Solution{ // Range Query and Range Update 
    vector<int> fenwickTree,lazyTree,arr;
    int n;
    void updateFenwickTree(int index, int value){
        while(index<n){
            fenwickTree[index]+=value;
            index += index & -index;
        }
    }
    void updateLazyTree(int index, int value){
        while(index<n){
            lazyTree[index]+=value;
            index += index & -index;
        }
    }
    int getSumFromFenwick(int index){
        int sum = 0;
        while(index>0){
            sum += fenwickTree[index];
            index -= index & -index;
        }
        return sum;
    }
    int getSumFromLazy(int index){
        int sum = 0;
        while(index>0){
            sum += lazyTree[index];
            index -= index & -index;
        }
        return sum;
    }
    
    void buildFenwickTree(){
        vector<int> prefixSum(n);
        for(int i = 1; i<n; i++){
            updateFenwickTreeInRange(i,i,arr[i]);
        }
    }
    void updateFenwickTreeInRange(int left, int right,int value){
        updateFenwickTree(left, value);
        updateFenwickTree(right+1,-value);
        updateLazyTree(left,value*(left-1));
        updateLazyTree(right+1,-value*right);
    }
    int getPrefixSum(int index){
        return getSumFromFenwick(index)*index - getSumFromLazy(index); 
    }
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        lazyTree.resize(n);
        fenwickTree.resize(n);
        buildFenwickTree();
    }
    int getAns(int left , int right){
        return getPrefixSum(right) - getPrefixSum(left-1);
    }
    void update(int left, int right,int value){
        updateFenwickTreeInRange(left, right, value);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i= 1; i<=n; i++){
        cin>>arr[i];
    }
    Solution obj(arr);
    int queryLen;
    cin>>queryLen;
    for(int i = 0; i<queryLen; i++){
        int type;
        cin>>type;
        int left;
        int right;
        cin>>left>>right;
        if(type == 0){
            cout<<obj.getAns(left+1,right+1)<<endl;
        }else{
            int val;
            cin>>val;
            obj.update(left+1, right+1, val);
        }
    }
}