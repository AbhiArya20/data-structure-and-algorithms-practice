#include<bits/stdc++.h>
using namespace std;

// GFG - BFS 

// For connected graph
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            ans.push_back(parent);
            for(auto child: adj[parent]){
                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
        return ans;
    }
};



// For disconnected graph
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    ans.push_back(parent);
                    for(auto child: adj[parent]){
                        if(!vis[child]){
                            q.push(child);
                            vis[child] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};




// Bi-Directional BFS - No need to learn this
class Solution{
    void bfsInnerWord(queue<int> &q, vector<bool> &vis, vector<int> &parent,vector<vector<int>> &adj){
        int src = q.front();
        q.pop();
        for(auto child: adj[src]){
            if(!vis[child]){
                vis[child]=true;
                q.push(child);
                parent[child]=src;
            }
        }
    }
    int intesectCheck(vector<bool> &visL, vector<bool> &visR){
        int n = visL.size();
        for(int i = 0; i<n; i++){
            if(visL[i] && visR[i])
                return i;
        }
        return -1;
    }
    vector<int> getAns(vector<int> &parL, vector<int> &parR,int intersectionPoint,int start, int goal){
        vector<int> ans;
        int intersection = intersectionPoint;
        while(intersection!=start){
            ans.push_back(intersection);
            intersection = parL[intersection];
        }
        intersection = intersectionPoint;
        while(intersection!=goal){
            ans.push_back(intersection);
            intersection = parR[intersection];
        }
        return ans;
    }
    vector<int> bfs(int start, int goal, vector<vector<int>> &adj){
        int n = adj.size();
        vector<bool> visL(n),visR(n);
        vector<int> parL(n),parR(n);
        queue<int> ql,qr;
        ql.push(start);
        qr.push(goal);
        visL[start]=visR[goal]=true;
        parL[start]=parR[goal]=-1;
        while (!ql.empty() && !qr.empty()){
            bfsInnerWord(ql,visL,parL,adj);
            bfsInnerWord(qr,visR,parR,adj);
            int isIntersect = intesectCheck(visL, visR);
            if(isIntersect!=-1){
                return getAns(parL, parR, isIntersect, start, goal);
            }
        }
        return {-1};
    }   
};