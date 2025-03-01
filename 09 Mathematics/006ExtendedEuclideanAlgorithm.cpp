#include<bits/stdc++.h>
using namespace std;

// GFG - Extended Euclidean Algorithm

// ax+by = gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// gcd(b,a%b) = bx1+(a%b)y1
// ax+by = bx1+(a%b)y1
// ax+by = bx1+(a-(a/b)*b)y1
// ax+by = bx1+ay1-((a/b)*b)y1
// ax+by = bx1-((a/b)*b)y1+ay1
// ax+by = b(x1-(a/b)*y1)+ay1


// x = y1
// y = x1 - (a/b)*y1

// base case if(b==0) gcd = a
//           ax+by = a
//           ax+0  == a
//           hence x = 1 and y = 0

class Solution{
    pair<int,pair<int,int>> euclidean(int a, int b){
        if(b==0){
            return {a,{1,0}};
        }
        auto prevAns = euclidean(b, a%b);
        int gcd = prevAns.first;
        int x1 = prevAns.second.second;
        int y1 = prevAns.second.first-(a/b)*prevAns.second.second;
        return {gcd, {x1, y1}};
    }
public:
    vector<int> gcd(int a, int b){
        int x = 0, y = 0;
        auto ans = euclidean(a, b);
        return {ans.first, ans.second.first, ans.second.second};
    }
};



// CP-Algorithm - https://cp-algorithms.com/algebra/linear-diophantine-equation.html
// Practice Link - https://nados.io/question/linear-diophantine-equation

class Solution { // Single solution
  pair<int, pair<int, int>>  euclidean(int a, int b) {
    if (b == 0) {
      return {a, {1, 0}};
    }
    auto prevAns = euclidean(b, a % b);
    int gcd = prevAns.first;
    int x1 = prevAns.second.second;
    int y1 = prevAns.second.first - (a / b) * prevAns.second.second;
    return {gcd, {x1, y1}};
  }
public:
  vector<int> solution(int a, int b,int c) {
    auto ans = euclidean(a, b);
    return {ans.second.first*c, ans.second.second*c};
  }
};

class Solution { // Multiple Solution
  pair<int, pair<int, int>>  euclidean(int a, int b) {
    if (b == 0) {
      return {a, {1, 0}};
    }
    auto prevAns = euclidean(b, a % b);
    int gcd = prevAns.first;
    int x1 = prevAns.second.second;
    int y1 = prevAns.second.first - (a / b) * prevAns.second.second;
    return {gcd, {x1, y1}};
  }
public:
  vector<vector<int>> solution(int a, int b,int c, int count) {
    int x = 0, y = 0;
    auto ans = euclidean(a, b);
    int gcd = ans.first;
    vector<vector<int>> res;
    res.push_back({ans.second.first*c, ans.second.second*c});
    while (count){
        res.push_back({res[0][0]-count*(b/gcd), res[0][1]+count*(a/gcd)});
        count--;
    }
    return res;
  }
};