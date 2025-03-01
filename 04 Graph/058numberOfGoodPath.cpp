#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2421

class Solution {
    class DSU {
public:
    vector<int> parent, rank;
    int size;
    DSU (int _n) {
        parent.resize(_n, -1);
        rank.resize(_n, 1);
        size = _n;
        for (int i = 0; i < _n; ++i) {
            parent[i] = i;
        }
    }
    int getParent(int u) {
        if (parent[u] != u) parent[u] = getParent(parent[u]);
        return parent[u];
    }
    void merge(int u, int v) {
        int x = getParent(u);
        int y = getParent(v);
        if (x == y) return ;
        if (rank[x] > rank[y]) swap(x, y);
        rank[y] += rank[x];
        parent[x] = y;
    }
};
public:
    static const int nax = 3e4 + 9;
    vector<int> g[nax];
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        for (auto &x: g) x.clear();
        
        for (const auto &e: edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        DSU dsu(n + 1);
        map<int, vector<int>> valueNodeMap;
        for (int i = 0; i < n; ++i) {
            valueNodeMap[vals[i]].push_back(i);
        }
        unordered_set<int> isNodeActive;
        long long paths = 0;
        for (auto [value, nodes]: valueNodeMap) {
            int components = 0;
            for (int node: nodes) isNodeActive.insert(node);
            for (int node: nodes) {
                for (int &v: g[node]) {
                    if (isNodeActive.count(v) > 0) {
                        dsu.merge(v, node);
                    }
                }
            }
            unordered_map<int, int> parentCountMap;
            for (int node: nodes) {
                ++parentCountMap[dsu.getParent(node)];
            }
            for (auto [a, b]: parentCountMap) {
                components += (b * (b - 1) / 2);
            }
            paths += components;
        } 
        return paths + n;
    }
};
