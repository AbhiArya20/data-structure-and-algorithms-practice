#include<bits/stdc++.h>
using namespace std;

// GFG - Dijkstra Algorithm

class Solution
{
    // It fail for negative weight
	public: // Using Priority Queue
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        vector<int> dist(V, 1e9);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int srcWt = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>dist[src]+childWt){
                    dist[child] = dist[src]+childWt;
                    pq.push({dist[child],child});
                }
            }
        }
        return dist;
    }
    
};

// Using Set
class Solution
{
    // It fail for negative weight
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
        vector<int> dist(V, 1e9);
        dist[src]=0;
        set<pair<int,int>> st;
        st.insert({0,src});
        while(!st.empty()){
            auto it = *(st.begin());
            int srcWt = it.first;
            int src = it.second;
            st.erase(it);
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>dist[src]+childWt){
                    dist[child] = dist[src]+childWt;
                    st.insert({dist[child],child});
                }
            }
        }
        return dist;
    }
};



// Using Queue but is not efficient it will increase no of iteration but it works.
class Solution
{
    // It fail for negative weight
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
        vector<int> dist(V, 1e9);
        dist[src]=0;
        queue<pair<int,int>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int srcWt = pq.front().first;
            int src = pq.front().second;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>dist[src]+childWt){
                    dist[child] = dist[src]+childWt;
                    pq.push({dist[child],child});
                }
            }
        }
        return dist;
    }
};