#include<bits/stdc++.h>
using namespace std;

// GFG - Shortest Prime Path

class Solution{    // UnAccepted 
    bool compare(int a, int b){
        int count = 0;
        string s1 = to_string(a);
        string s2 = to_string(b);
        for(int i = 0; i<4; i++){
            if(s1[i]!=s2[i])
                count++;
        }
        return count == 1;
    }
public:
    int solve(int Num1,int Num2)
    {   
      int n = 10000; 
      vector<int> isPrime(10000, true);
      for(int i = 2; i*i<n; i++){
          if(isPrime[i]){
              for(int j = i*i; j<=n;j+=i){
                  isPrime[j]=false;
              }
          }
      }
      vector<int> primes;
      int start = 0;
      for(int i = 1000; i<n; i++){
          if(isPrime[i]){
              if(Num1 == i){
                  start = primes.size();
              }
              primes.push_back(i);
          }
          
      }
      vector<vector<int>> adj(primes.size());
      for(int i = 0; i<primes.size(); i++){
          for(int j = i+1; j<primes.size(); j++){
              if(compare(primes[i],primes[j])){
                  adj[i].push_back(j);
                  adj[j].push_back(i);
              }
          }
      }
      vector<int> vis(primes.size());
      queue<int> q;
      q.push(start);
      vis[start]=true;
      int ans = 0;
      while(!q.empty()){
          int size = q.size();
          for(int i = 0; i<size; i++){
              int top = q.front();
              q.pop();
              if(primes[top] == Num2)
                return ans;
              for(auto child: adj[top]){
                  if(!vis[child]){
                      vis[child]=true;
                      q.push(child);
                  }
              }
          }
          ans++;
      }
      return -1;
    }
};


// Accepted
vector<bool> isPrime(10000,true);
class Solution{   
    static bool isFirst;
    static void sieve(){
        if(!isFirst)
            return;
        isFirst=false;
        isPrime[0]=isPrime[1]=false;
        for(int i=4;i<1e4;i+=2)
            isPrime[i]=false;
        for(int i=3;i*i<=9999;i+=2){
            if(isPrime[i]){
                for(int j=i*i;j<1e4;j+=(i<<1))
                    isPrime[j]=false;
            }
        }
    }   
    public:
    Solution(){
        sieve();
    }
    int solve(int Num1,int Num2)
    {   
        int ans=0;
        queue<int> q;
        bool vis[10000]={false};
        q.push(Num1);
        vis[Num1]=true;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int u=q.front();
                q.pop();
                if(u==Num2)
                    return ans;
                string curr=to_string(u);
                for(int i=0;i<4;i++){
                    char c=curr[i];
                    for(int j=0;j<10;j++){
                        if(!i && !j)
                            continue;
                        curr[i]='0'+j;
                        int v=stoi(curr);
                        if(isPrime[v] && !vis[v])
                            q.push(v),vis[v]=true;
                    }
                    curr[i]=c;
                }
            }
            ans++;
        }
        return -1;
    }
};
bool Solution::isFirst=true;