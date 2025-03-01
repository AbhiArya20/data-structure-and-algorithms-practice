#include<bits/stdc++.h>
using namespace std;

// Practice Link - https://nados.io/question/k-th-ancestor?zen=true

class Solution{
    vector<vector<int>> table;
    void buildTable(vector<int> parent){
        int maxRow = 31;
        int n = parent.size();
        table.resize(maxRow,vector<int>(n));
        for(int i = 0; i<n; i++)
            table[0][i] = parent[i];
            
        for(int i = 1; i<maxRow; i++){
            for(int j = 0; j<n; j++){
                table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }
    public:
    vector<int> binaryLifting(vector<int> parent, vector<vector<int>> query){
        int maxRow = 31;
        buildTable(parent);
        vector<int> ans;
        for(auto v: query){
            for(int i = 0; i<maxRow; i++){
                if((v[1] & (1<<i))){
                    v[0] = table[i][v[0]];
                }
            }  
            ans.push_back(v[0]);
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> parent(n);
    for(int i = 0; i<n; i++)
        cin>>parent[i];
    int m;
    cin>>m;
    vector<vector<int>> query;
    for(int i = 0; i<m; i++){
        int x,y;
        cin>>x>>y;
        query.push_back({x,y});
    }
    Solution obj;
    auto ans = obj.binaryLifting(parent,query);
    for(auto v: ans)
        cout<<v<<endl;
}