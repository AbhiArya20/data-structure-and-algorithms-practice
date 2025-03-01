#include<bits/stdc++.h>
using namespace std;

// GFG - Square Root Decomposition
class Solution{
    vector<int> sqrtArr;
    void buildSqrtArr(vector<int> &arr){
        int n = arr.size();
        int sizeOfSqrtArr = ceil(sqrt(n));
        sqrtArr.resize(sizeOfSqrtArr,INT_MAX);
        for(int i = 0; i<n; i++){
            int sqrtArrIdx = i/sizeOfSqrtArr;
            sqrtArr[sqrtArrIdx] = min(sqrtArr[sqrtArrIdx], arr[i]);
        }
    }
    int sqrtDecom(vector<int> &arr,int left, int right){
        int n = arr.size();
        int sizeOfSqrtArr = ceil(sqrt(n));
        int ans = INT_MAX;
        while(left <= right){
            if(left%sizeOfSqrtArr == 0 && left+sizeOfSqrtArr-1 <= right){
                ans = min(ans, sqrtArr[left/sizeOfSqrtArr]);
                left+=sizeOfSqrtArr;
            }else{
                ans = min(ans, arr[left]);
                left++;
            }
        }
        return ans;
    }
    public:
    vector<int>  getAns(vector<int> arr, vector<vector<int>> querie){
        buildSqrtArr(arr);
        vector<int> ans;
        for(auto que: querie){
            int left = que[0];
            int right = que[1];
            ans.push_back(sqrtDecom(arr,left, right));
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    Solution obj;
    int query;
    cin>>query;
    vector<vector<int>> queries;
    while(query--){
        int left, right;
        cin>>left>>right;
        queries.push_back({left, right});
    } 
    auto ans = obj.getAns(arr, queries);
    for(auto v: ans){
        cout<<v<<endl;
    }
}




// Point Update In Square Root Decomposition
class Solution{
    vector<int> sqrtArr;
    void buildSqrtArr(vector<int> &arr){
        int n = arr.size();
        int sizeOfSqrtArr = ceil(sqrt(n));
        sqrtArr.resize(sizeOfSqrtArr);
        for(int i = 0; i<n; i++){
            int sqrtArrIdx = i/sizeOfSqrtArr;
            sqrtArr[sqrtArrIdx] += arr[i];
        }
    }
    int sqrtDecom(vector<int> &arr,int left, int right){
        int n = arr.size();
        int sizeOfSqrtArr = ceil(sqrt(n));
        int ans = 0;
        while(left <= right){
            if(left%sizeOfSqrtArr == 0 && left+sizeOfSqrtArr-1 <= right){
                ans += sqrtArr[left/sizeOfSqrtArr];
                left+=sizeOfSqrtArr;
            }else{
                ans += arr[left];
                left++;
            }
        }
        return ans;
    }
    void updateSqrtArr(int index, int value, int n, vector<int> &arr){
        arr[index]+=value;
        int sizeOfSqrtArr = ceil(sqrt(n));
        sqrtArr[index/sizeOfSqrtArr]+=value;
    }
    public:
    vector<int>  getAns(vector<int> &arr, vector<vector<int>> &querie){
        buildSqrtArr(arr);
        int n = arr.size();
        vector<int> ans;
        for(auto que: querie){
            int type = que[0];
            if(type){
                int left = que[1];
                int right = que[2];
                ans.push_back(sqrtDecom(arr,left, right));
            }else{
                int index = que[1];
                int value = que[2];
                updateSqrtArr(index,value,n,arr);
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    Solution obj;
    int query;
    cin>>query;
    vector<vector<int>> queries;
    while(query--){
        char type;
        int left, right;
        cin>>type>>left>>right;
        queries.push_back({type=='f',left, right});
    } 
    auto ans = obj.getAns(arr, queries);
    for(auto v: ans){
        cout<<v<<endl;
    }
}