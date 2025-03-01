#include<bits/stdc++.h>
using namespace std;

// LeetCode - 297

class Codec {
public:
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto front = q.front();
                q.pop();
                if(!front){
                    ans+="N-";
                }else{
                    if(front->left){
                        q.push(front->left);
                    }else{
                        q.push(NULL);
                    }
                    if(front->right){
                        q.push(front->right);
                    }else{
                        q.push(NULL);
                    }
                    if(front->val < 0){
                        ans += "*"+to_string(-front->val)+"-";
                    }else{
                        ans+=to_string(front->val)+"-";
                    }
                }
            }
        }
        ans.pop_back();
        return ans;
    }
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        if(data == "N")
            return NULL;
        vector<TreeNode*> ans;
        int n = data.size();
        for(int i = 0; i<n; i++){
            if(data[i]=='-')
                continue;
            if(data[i]=='N')
                ans.push_back(NULL);
            else if(data[i]=='*'){
                i++;
                int val = 0;
                while(isdigit(data[i])){
                    val*=10;
                    val+=(int)(data[i]-'0');
                    i++;
                }
                ans.push_back(new TreeNode(-val));
            }else{
                int val = 0;
                while(isdigit(data[i])){
                    val*=10;
                    val+=(int)(data[i]-'0');
                    i++;
                }
                ans.push_back(new TreeNode(val));
            }
        }
        queue<TreeNode*> q;
        int i = 1;
        q.push(ans[0]);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                front->left = ans[i];
                i++;
                front->right = ans[i];
                i++;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        }
        return ans[0];
    }
};