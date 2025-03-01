#include<bits/stdc++.h>
using namespace std;


// GFG - Bucket Sort - To sort floating point numbers in range (0.0 - 1.0)

class Solution{
    public:
    void bucketSort(vector<float> &arr){
        int n = arr.size();
        vector<vector<float>> temp(n);

        for(auto val : arr){
            int idx = val*n; 
            temp[idx].push_back(val);
        }

        for(auto miniTemp: temp){
            sort(miniTemp.begin(), miniTemp.end());
        }

        arr.clear();
        for(auto miniTemp: temp){
            for(auto val: miniTemp){
                arr.push_back(val);
            }
        }

    }
};