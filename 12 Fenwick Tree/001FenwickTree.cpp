#include<bits/stdc++.h>
using namespace std;

// GFG - Fenwick Tree
// Practice Link - https://nados.io/question/fenwick-tree?zen=true 


// fenwick tree is build on 1-base index
class Solution{ // Build is O(nlogn) 
    vector<int> fenwickTree,arr;
    int n;
    void updateFenwickTree(int index, int value){
        while(index<n){
            fenwickTree[index]+=value;
            index += index & -index;
        }
    }
    int getPrefixSum(int index){
        int sum = 0;
        while(index>0){
            sum += fenwickTree[index];
            index -= index & -index;
        }
        return sum;
    }
    void buildFenwickTree(){
        for(int i = 1; i<n; i++){
            updateFenwickTree(i,arr[i]);
        }
    }
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        fenwickTree.resize(n);
        buildFenwickTree();
    }
    int getAns(int left , int right){
        return getPrefixSum(right) - getPrefixSum(left-1);
    }
    void update(int index, int value){
        updateFenwickTree(index, value);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i = 1; i<=n; i++)
        cin>>arr[i];
    Solution obj(arr);
    int q;
    cin>>q;
    while(q--){
        char type;
        cin>>type;
        if(type=='q'){
            int left,right;
            cin>>left>>right;
            cout<<obj.getAns(left, right)<<endl;
        }else{
            int index,value;
            cin>>index>>value;
            obj.update(index,value);
        }
    }
}



class Solution{ // Build is O(n) 
    vector<int> fenwickTree,arr;
    int n;
    void updateFenwickTree(int index, int value){
        while(index<n){
            fenwickTree[index]+=value;
            index += index & -index;
        }
    }
    int getPrefixSum(int index){
        int sum = 0;
        while(index>0){
            sum += fenwickTree[index];
            index -= index & -index;
        }
        return sum;
    }
    void buildFenwickTree(){
        vector<int> prefixSum(n);
        for(int i = 1; i<n; i++){
            prefixSum[i] = arr[i] + prefixSum[i-1];
        }
        for(int rightIndex = 1; rightIndex<n; rightIndex++){
            int leftIndex = rightIndex - (rightIndex & -rightIndex);
            fenwickTree[rightIndex] = prefixSum[rightIndex]-prefixSum[leftIndex];
        }
    }
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        fenwickTree.resize(n);
        buildFenwickTree();
    }
    int getAns(int left , int right){
        return getPrefixSum(right) - getPrefixSum(left-1);
    }
    void update(int index, int value){
        updateFenwickTree(index, value);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i = 1; i<=n; i++)
        cin>>arr[i];
    Solution obj(arr);
    int q;
    cin>>q;
    while(q--){
        char type;
        cin>>type;
        if(type=='q'){
            int left,right;
            cin>>left>>right;
            cout<<obj.getAns(left, right)<<endl;
        }else{
            int index,value;
            cin>>index>>value;
            obj.update(index,value);
        }
    }
}