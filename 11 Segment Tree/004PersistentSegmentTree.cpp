#include<bits/stdc++.h>
using namespace std;

// GFG - Persistent Segment Tree

class Solution{
    vector<int> arr;
    int n;
    class Node{
        int sum;
        Node* left;
        Node* right;
        public:
        Node(int sum){
            this->sum = sum;
            left = NULL;
            right = NULL;
        }
        Node(Node* leftChild, Node* rightChild){
            this->sum = leftChild->sum + rightChild->sum;
            left = leftChild;
            right = rightChild;
        }
        Node* getRight(){
            return this->right;
        }
        Node* getLeft(){
            return this->left;
        }
    };
    vector<Node*> pastNodes;
    Node* BuildTree(int start, int end){
        if(start == end)
            return new Node(arr[start]);
        int mid = (start+end)>>1;
        Node* leftChild = BuildTree(start, mid);
        Node* rightChild = BuildTree(mid+1, end);
        return new Node(leftChild, rightChild);        
    }
    Node* update(Node* node, int start, int end, int index, int val){
        if(start == end)
            return new Node(val);
        int mid = (start + end)>>1;
        if(index<=mid)
            return new Node(update(node->getLeft(),start,mid,index,val), node->getRight());
        return new Node(node->getLeft(),update(node->getRight(),start,mid,index,val));
    }
    public:
    Solution(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        Node* head = BuildTree(0,n-1);
        pastNodes.push_back(head);
    }
    void update(int index, int val){
        Node* prevUpdate = pastNodes[pastNodes.size()-1];
        Node* head = update(prevUpdate, 0, n-1,index,val);
        pastNodes.push_back(head);
    }
};