#include <bits/stdc++.h>
using namespace std;


// Practice link - https://nados.io/question/monkey-tradition?zen=true

class Solution{
    pair<long long,pair<long long,long long>> euclidean(long long a, long long b){
        if(b==0){
            return {a,{1,0}};
        }
        auto prevAns = euclidean(b, a%b);
        long long gcd = prevAns.first;
        long long x1 = prevAns.second.second;
        long long y1 = prevAns.second.first-(a/b)*prevAns.second.second;
        return {gcd, {x1, y1}};
    }
    public:
    string chineseReminderTheorem(int n, vector<long long> &pi, vector<long long> &ri){
        vector<string> res;
        long long a1 = ri[0];
        long long n1 = pi[0];
        for(int i = 1; i<n; i++){
            long long a2 = ri[i];
            long long n2 = pi[i];
            auto euclid = euclidean(n1,n2);
            long long x = euclid.second.first;
            long long gcd = euclid.first;
            if((a1-a2)%gcd != 0){
                return "Impossible";
            }else{
                long long k = (a1-a2)/gcd;
                long long lcm = n1*n2/__gcd(n1,n2);
                long long ans = a1-n1 *(k*x %(n2/gcd));
                if(ans<0)
                    ans += lcm;
                a1 = ans;
                n1 = lcm;
            }
        }
        return to_string(a1);
    }
};
int main(){
    int t;
    cin>>t;
    int i = 1;
    while(t--){
        int n;
        cin>>n;
        vector<long long> pi(n),ri(n);
        for(int i = 0; i<n; i++){
            cin>>pi[i]>>ri[i];
        }
        Solution obj;
        auto ans = obj.chineseReminderTheorem(n,pi,ri);
        cout<<"Case "<<i<<":"<<" "<<ans<<endl;
        i++;
    }
}