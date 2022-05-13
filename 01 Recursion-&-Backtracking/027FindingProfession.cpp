#include<bits/stdc++.h>
using namespace std;

// GFG - Finding Profession
// LeetCode - 779

class Solution{
public:
    char profession(int level, int pos){
        if(pos == 1)
            return 'e';
        if(profession(level-1, (pos+1)/2) == 'e')
            return pos%2 ? 'e':'d';
        return pos%2 ? 'd':'e';
    }
};