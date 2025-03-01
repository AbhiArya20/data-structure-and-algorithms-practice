#include<bits/stdc++.h>
using namespace std;

// LeetCode - 421 

class Solution {
    class Node{
        public:
        Node* left;
        Node* right;
    };
    Node* root;
    void insert(int v){
        Node* cur = root;
        int bitIdx = 30;
        while(bitIdx >= 0){
            int mask = 1<<bitIdx;
            int bit = mask&v;
            if(bit){
                if(!cur->right){
                    cur->right = new Node();
                }
                cur = cur->right;
            }else{
                if(!cur->left){
                    cur->left = new Node();
                }
                cur = cur->left;
            }
            bitIdx--;
        }
    }
    int find(int v){
        Node* cur = root;
        int ans = 0;
        int bitIdx = 30;
        while(bitIdx >= 0){
            int mask = 1<<bitIdx;
            int bit = mask&v;
            if(bit){
                if(cur->right){
                    cur = cur->right;
                    ans |= mask;
                }else{
                    cur = cur->left;
                }
            }else{
                if(cur->left){
                    cur = cur->left;
                }else{
                    cur = cur->right;
                    ans |= mask; 
                }
            }
            bitIdx--;
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        for(auto v: nums)
            insert(v);
        int ans = 0;
        for(auto v: nums){
            int maxi = ~v;
            int res = find(maxi);
            ans = max(ans, res^v);
        }
        return ans;
    }
};