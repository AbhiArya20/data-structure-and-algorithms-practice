#include<bits/stdc++.h>
using namespace std;

// GFG - Temple Offering

class Solution{
public:
    int offerings(int n, int arr[]){
        int ans  = 0;
        vector<int> dpleftToright(n), dprightToleft(n);
        dpleftToright[0]=1;
        dprightToleft[n-1]=1;
        for(int i = 1; i<n; i++){
            if(arr[i]>arr[i-1])
                dpleftToright[i] = dpleftToright[i-1]+1;
            else
                dpleftToright[i] = 1;
        }
        for(int i = n-2; i>=0; i--){
            if(arr[i]>arr[i+1])
                dprightToleft[i] = dprightToleft[i+1]+1;
            else
                dprightToleft[i] = 1;
        }
        for(int i = 0; i<n; i++)
            ans += max(dprightToleft[i] , dpleftToright[i]);
        return ans;
    }
};