#include<bits/stdc++.h>
using namespace std;

// GFG - Fractional Knapsack

class Solution{
    public:
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr+n, [](Item a, Item b){
            return (double)a.value/a.weight > (double)b.value/b.weight;
        });
        double ans = 0;
        for(int i = 0; i<n; i++){
            if(W>=arr[i].weight){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                ans += W*((double)arr[i].value/arr[i].weight);
                break;
            }
        }
        return ans;
    }
};