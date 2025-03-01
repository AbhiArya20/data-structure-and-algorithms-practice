#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2458

class Solution {
    class SegmentTree{
        int n;
        vector<int> arr;
        vector<int> segmentTree;
        void buildSegment(int index, int start, int end){
            if(start == end){
                segmentTree[index] = arr[start];
                return;
            }

            int mid = (start+end)>>1;
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            buildSegment(leftIndex, start, mid);
            buildSegment(rightIndex, mid+1, end);

            segmentTree[index] = max(segmentTree[leftIndex], segmentTree[rightIndex]);
        }
        int getMaxFromSegment(int index, int start, int end, int left,int right){
            if(end<left || start>right)
                return 0;
            if(start >= left && end<=right){    
                return segmentTree[index];
            }
            
            int mid = (start+end)>>1;
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            int leftAns = getMaxFromSegment(leftIndex, start, mid, left, right);
            int rightAns = getMaxFromSegment(rightIndex, mid+1, end, left, right);

            return max(leftAns, rightAns);
        }
        public:    
        SegmentTree(vector<int> &arr){
            n = arr.size();
            this->arr = arr;
            segmentTree.resize(4*n);
            buildSegment(1,0,n-1);
        }
        int getMax(int left, int right){
            return getMaxFromSegment(1,0,n-1,left,right);
        }
    };
    int sizeOfTree(TreeNode* root){
        return (!root)? 0:1+sizeOfTree(root->left)+sizeOfTree(root->right);
    }
    void eularTour(TreeNode* root,int &timer,int depth,vector<int>&start,vector<int>&end,vector<int>&depths){
        if(!root)
            return;
        start[root->val] = ++timer;
        depths[timer] = depth;
        eularTour(root->left,timer,depth+1,start,end,depths);
        eularTour(root->right,timer,depth+1,start,end,depths);
        end[root->val] = ++timer;
        depths[timer] = depth;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int size = sizeOfTree(root);
        vector<int> start(size+1),end(size+1),depths(2*size+1);
        int timer = 0;
        eularTour(root,timer,0,start,end,depths);
        SegmentTree obj(depths);
        int ans = size;
        int m = queries.size();
        vector<int> res;
        for(auto &v: queries){
            int one = obj.getMax(0,start[v]-1);
            int two = obj.getMax(end[v]+1,2*size);
            int ans = max(one,two);
            res.push_back(ans);
        }
        return res;
    }
};