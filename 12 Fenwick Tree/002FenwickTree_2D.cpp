#include<bits/stdc++.h>
using namespace std;

// GFG - Fenwick Tree 2D
// Practice Link - https://nados.io/question/2d-binary-indexed-tree?zen=true

class Solution{
    vector<vector<int>> fenwickTree,arr;
    int n,m;
    void updateFenwickTree(int row,int col,int value){
        int curRow = row;
        while(curRow<n){
            int curCol = col;
            while(curCol<m){
                fenwickTree[curRow][curCol] += value;
                curCol += curCol & -curCol;
            }
            curRow += curRow & -curRow;
        }
    }
    int getPrefixSum(int row, int col){
        int sum = 0;
        int curRow = row;
        while(curRow>0){
            int curCol = col;
            while(curCol>0){
                sum += fenwickTree[curRow][curCol];
                curCol -= curCol & -curCol;
            }
            curRow -= curRow & -curRow;
        }
        return sum;
    }
    void buildFenwickTree(){
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                update(i,j,arr[i][j]);
            }
        }
    }
    public:
    Solution(vector<vector<int>> arr){
        n = arr.size();
        m = arr[0].size();
        this->arr = arr;
        fenwickTree.resize(n,vector<int>(m));
        buildFenwickTree();
    }
    int getAns(int row1,int col1,int row2,int col2){
        return getPrefixSum(row2,col2) + getPrefixSum(row1-1,col1-1) - getPrefixSum(row2,col1-1) - getPrefixSum(row1-1,col2);
    } 
    void update(int row,int col,int value){
        updateFenwickTree(row,col,value);
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1,vector<int>(m+1));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    Solution obj(arr);
    int q;
    cin>>q;
    while(q--){
        char type;
        cin>>type;
        if(type=='q'){
            int row1,col1,row2,col2;
            cin>>row1>>col1>>row2>>col2;
            cout<<obj.getAns(row1,col1,row2,col2)<<endl;
        }else{
            int row,col,value;
            cin>>row>>col>>value;
            obj.update(row,col,value);
        }
    }
}