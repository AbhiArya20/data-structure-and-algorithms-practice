#include<bits/stdc++.h>
using namespace std;

class Solution{
    class Fenwick{ // Build is O(n) 
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
        Fenwick(vector<int> arr){
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
    vector<int> start,end,value;
    void dfs(int node, int &timer,int parent, vector<int> &arr, vector<vector<int>> &adj){
        start[node] = ++timer;
        value[timer] = arr[node];
        for(auto child: adj[node]){
            if(child != parent)
                dfs(child,timer,node,arr,adj);
        }
        end[node] = timer;
    }
    Fenwick *fenwick;
    public:
    Solution(vector<int> arr, vector<vector<int>> adj){
        int n = arr.size();
        start.resize(n);
        end.resize(n);
        value.resize(n);
        int timer = 0;
        dfs(1,timer,-1,arr,adj);
        fenwick = new Fenwick(value);
    }
    void update(int vertex, int value){
        int val = value;
        val -= this->value[vertex];
        this->value[vertex] = value;
        fenwick->update(vertex,val);
    }
    int getAns(int vertex){
        return fenwick->getAns(start[vertex], end[vertex]);
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1);
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Solution obj(arr, adj);
    while(q--){
        int type,vertex; 
        cin>>type>>vertex;
        if(type == 1){
            int value;
            cin>>value;
            obj.update(vertex,value);
        }else{
            cout<<obj.getAns(vertex)<<endl;
        }
    }
}