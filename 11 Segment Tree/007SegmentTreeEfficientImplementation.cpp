#include<bits/stdc++.h>
using namespace std;

// GFG - Efficient Implementation
// Need strong knowledge about Bit-Manipulation
// CodeForce - https://codeforces.com/blog/entry/18051

class Solution{ // Point Update - Range Query
    int n;
    vector<int> arr;
    vector<int> segmentTree;
    void buildSegment() { 
        for (int i=0; i<n; i++)    
            segmentTree[n+i] = arr[i];
        
        for (int i = n - 1; i > 0; --i)     
            segmentTree[i] = segmentTree[i<<1] + segmentTree[i<<1 | 1];    
    }
    void updateSegment(int index, int value) { 
        index = index+n;
        segmentTree[index] = value;
        
        for (int i=index; i > 1; i >>= 1)
            segmentTree[i>>1] = segmentTree[i] + segmentTree[i^1];
    }
  
    int getAns(int left, int right) { 
        int res = 0;
        for (left += n, right += n; left <= right; left >>= 1, right >>= 1)
        {
            if (left&1) 
                res += segmentTree[left++];
        
            if (!(right&1)) 
                res += segmentTree[right--];
        }
        return res;
    }
    
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(2*n);
        buildSegment();
    }
    int getSum(int left, int right){
        return getAns(left,right);
    }
    void update(int index, int val){
        updateSegment(index,val);
    }
};



// class Solution{ // Range Update - Point Query
//     int n;
//     vector<int> arr;
//     vector<int> segmentTree;
//     void buildSegment() { 
//         for (int i=0; i<n; i++)    
//             segmentTree[n+i] = arr[i];
        
//         for (int i = n - 1; i > 0; --i)     
//             segmentTree[i] = segmentTree[i<<1] + segmentTree[i<<1 | 1];    
//     }
//     void updateSegment(int left, int right, int value) { 
//         for (left += n, right += n; left < right; left >>= 1, right >>= 1){
//             if (left&1) 
//                 segmentTree[left++]+=value;
        
//             if (!(right&1)) 
//                 segmentTree[right--]+=value;
//         }
//     }
  
//     int getAns(int index) { 
//         int res = 0;
//         for(index+=n; index>0; index>>=1)
//             res += segmentTree[index];
//         return res;
//     }
    
//     public:
//     Solution(vector<int> arr){
//         n = arr.size();
//         this->arr = arr;
//         segmentTree.resize(2*n);
//         buildSegment();
//     }
//     void update(int left, int right, int value){
//         return update(left,right,value);
//     }
//     int getSum(int index){
//         getAns(index);
//     }
// };
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i= 0; i<n; i++){
//         int x;
//         cin>>x;
//         arr.push_back(x);
//     }
//     Solution obj(arr);
//     int queryLen;
//     cin>>queryLen;
//     for(int i = 0; i<queryLen; i++){
//         int type;
//         cin>>type;
//         if(type == 0){
//             int idx;
//             cin>>idx;
//             cout<<obj.getSum(idx)<<endl;
//         }else{
//             int left;
//             int right;
//             int val;
//             cin>>left>>right>>val;
//             obj.update(left, right, val);
//         }
//     }
// }
