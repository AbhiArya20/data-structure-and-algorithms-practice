#include<bits/stdc++.h>
using namespace std;

// GFG - 2D Segment Tree
// Practice Link - https://nados.io/question/2d-segment-tree?zen=true

class Solution{
    int n,m;
    vector<vector<int>> arr, segmentTree;

    void buildSegment_Y(int index_Y, int start_Y, int end_Y, int index_X, int start_X, int end_X){
        if(start_Y == end_Y){
            if(start_X == end_X){
                segmentTree[index_X][index_Y] = arr[start_X][start_Y];
            }else{
                segmentTree[index_X][index_Y] = segmentTree[index_X*2][index_Y]+segmentTree[index_X*2+1][index_Y];
            }
            return;
        }
        int mid = (start_Y+end_Y)>>1;
        int leftIndex = index_Y*2;
        int rightIndex = index_Y*2+1;
        buildSegment_Y(leftIndex,start_Y,mid,index_X,start_X,end_X);
        buildSegment_Y(rightIndex,mid+1,end_Y,index_X,start_X,end_X);
        segmentTree[index_X][index_Y] = segmentTree[index_X][leftIndex]+segmentTree[index_X][rightIndex];
    }
    void buildSegment_X(int index_X, int start_X, int end_X){
        if(start_X == end_X){
            buildSegment_Y(1,1,m-1,index_X,start_X,end_X);
            return;
        }
        int mid = (start_X+end_X)>>1;
        int leftIndex = index_X*2;
        int rightIndex = index_X*2+1;
        buildSegment_X(leftIndex, start_X, mid);
        buildSegment_X(rightIndex,mid+1, end_X);
        buildSegment_Y(1,1,m-1,index_X,start_X,end_X);
    }
    void updateSegment_Y(int index_Y,int start_Y, int end_Y, int index_X,int start_X, int end_X, int row, int col, int val){
        if(start_Y == end_Y){
            if(start_X == end_X){
                arr[start_X][start_Y] = val;
                segmentTree[index_X][index_Y] += val;
            }else{
                segmentTree[index_X][index_Y] = segmentTree[index_X*2][index_Y]+segmentTree[index_X*2+1][index_Y];
            }
            return;
        }
        int mid = (start_Y+end_Y)>>1;
        int leftIndex = index_Y*2;
        int rightIndex = index_Y*2+1;
        
        if(col<=mid)
            updateSegment_Y(leftIndex, start_Y, mid, index_X, start_X, end_X, row, col, val);
        else
            updateSegment_Y(rightIndex, mid+1, end_Y, index_X, start_X, end_X, row, col, val);

        segmentTree[index_X][index_Y] = segmentTree[index_X][leftIndex]+segmentTree[index_X][rightIndex];
    }
    void updateSegment_X(int index_X,int start_X, int end_X, int row, int col, int val){
        if(start_X == end_X){
            updateSegment_Y(1,1,m-1,index_X, start_X,end_X,row,col,val);
            return;
        }
        int mid = (start_X+end_X)>>1;
        int leftIndex = index_X*2;
        int rightIndex = index_X*2+1;

        if(row<=mid)
            updateSegment_X(leftIndex, start_X, mid, row, col, val);
        else
            updateSegment_X(rightIndex,mid+1, end_X, row, col, val);
        
        updateSegment_Y(1,1,m-1,index_X, start_X,end_X,row,col,val);
    }
    int getSum_Y(int index_Y, int start_Y, int end_Y, int index_X, int start_X, int end_X, int col1, int col2){
        if(end_Y<col1 || start_Y>col2)
            return 0;
        if(start_Y>=col1 && col2>=end_Y){
            return segmentTree[index_X][index_Y];
        }
        int mid = (start_Y+end_Y)>>1;
        int leftIndex = index_Y*2;
        int rightIndex = index_Y*2+1;

        int leftAns = getSum_Y(leftIndex,start_Y,mid,index_X,start_X,end_X,col1,col2);
        int rightAns = getSum_Y(rightIndex,mid+1,end_Y,index_X,start_X,end_X,col1,col2);

        return leftAns + rightAns;
    }
    int getSum_X(int index_X, int start_X, int end_X, int row1, int col1, int row2, int col2){
        if(end_X<row1 || start_X>row2)
            return 0;
        if(start_X>=row1 && row2>=end_X){
            return getSum_Y(1,1,m-1,index_X,start_X,end_X,col1,col2);
        }
        int mid = (start_X+end_X)>>1;
        int leftIndex = index_X*2;
        int rightIndex = index_X*2+1;

        int leftAns = getSum_X(leftIndex,start_X,mid,row1,col1,row2,col2);
        int rightAns = getSum_X(rightIndex,mid+1,end_X,row1,col1,row2,col2);

        return leftAns + rightAns;
    }
    
    public:
    Solution(vector<vector<int>> arr){
        n = arr.size();
        m = arr[0].size();
        this->arr = arr;
        segmentTree.resize(4*n,vector<int>(4*m));
        buildSegment_X(1,1,n-1);
    }
    void update(int row, int col, int val){
        updateSegment_X(1,1,n-1,row,col,val);
    }
    int getAns(int row1, int col1, int row2, int col2){
        return getSum_X(1,1,n-1,row1,col1,row2,col2);
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
        char st;
        cin>>st;
        if(st == 'q'){
            int row1,col1,row2,col2;
            cin>>row1>>col1>>row2>>col2;
            cout<<obj.getAns(row1,col1,row2,col2)<<endl;
        }else{
            int row,col,val;
            cin>>row>>col>>val;
            obj.update(row,col,val);
        }
    }
}