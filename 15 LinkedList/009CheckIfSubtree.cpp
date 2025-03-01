#include<bits/stdc++.h>
using namespace std;

// GFG - Check If Subtree
// LeetCode - 572

class Solution{
    bool check(Node* T, Node* S) {
        if(!T && !S)
            return true;
        if(!T || !S)
            return false;
        if(T->data != S->data)
            return false;
        return check(T->left,S->left) && check(T->right,S->right);
    }
  public:
    bool isSubTree(Node* T, Node* S) {
        if(!T && !S)
            return true;
        if(!T || !S)
            return false;
        return check(T,S) || isSubTree(T->left,S) || isSubTree(T->right,S);
    }
};