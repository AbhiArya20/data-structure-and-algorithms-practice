#include<bits/stdc++.h>
using namespace std;

// GFG - Sparse Table - Range Minimum Query - O(1)

class Solution{
    vector<vector<int>> sparseTable;
    vector<int> arr;
    int n;
    void buildSparseTable(){
        int sizeOfSparseTable = log2(n);
        sparseTable[0] = arr;
        for(int i = 1; i<=sizeOfSparseTable; i++){
            for(int j = 0; j+(1<<i)<=n; j++){
                sparseTable[i][j] = min(sparseTable[i-1][j],sparseTable[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int getMin(int left, int right){
        int count = right-left+1;
        int sizeOfRange = log2(count);
        return min(sparseTable[sizeOfRange][left],sparseTable[sizeOfRange][right-(1<<sizeOfRange)+1]);
    }
    public:
    Solution(vector<int> &arr){
        n = arr.size();
        this->arr = arr;
        int sizeOfSparseTable = log2(n);
        sparseTable.resize(sizeOfSparseTable+1,vector<int>(n));
        buildSparseTable();
    }
    int getAns(int left, int right){
        return getMin(left,right);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    Solution obj(arr);
    int q;
    cin>>q;
    while(q--){
        int left, right;
        cin>>left>>right;
        int ans = obj.getAns(left, right);
        cout<<ans<<endl;
    }
}