#include<bits/stdc++.h>
using namespace std;

// LeetCode - 222

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = 0;        
        int right_height = 0;        
        TreeNode* left_pointer = root;
        TreeNode* right_pointer = root;        
        while(left_pointer){
            left_height++;            
            left_pointer = left_pointer -> left;
        }
        while(right_pointer){
            right_height++;            
            right_pointer = right_pointer -> right;
        }
        if(left_height == right_height)
            return pow(2, left_height) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};