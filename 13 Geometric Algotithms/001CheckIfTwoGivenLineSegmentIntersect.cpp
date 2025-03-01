#include<bits/stdc++.h>
using namespace std;

// GFG - Check If Two Given Line Segment Intersect

class Solution {
    bool onSegment(int first[],int second[], int which[]){
        return (which[0] >= min(first[0],second[0]) && which[0] <= max(first[0],second[0])) && (which[1] >= min(first[1],second[1]) && which[1] <= max(first[1],second[1]));
    }
    int orientation(int first[],int second[],int from[]){
        int val = (first[0]-from[0]) * (second[1]-from[1]) - (first[1]-from[1]) * (second[0]-from[0]); 
        if(val == 0) return 0; // Collinear
        else if(val>0) return 1; // ClockWise
        else return 2; // AntiClockWise
    }
  public:
    int doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int ori1 = orientation(p1,q1,p2);
        int ori2 = orientation(p1,q1,q2);
        int ori3 = orientation(p2,q2,p1);
        int ori4 = orientation(p2,q2,q1);
        if(ori1 != ori2 && ori3 != ori4)
            return true;
        if(
            (ori1==0 && onSegment(p1,q1,p2)) ||
            (ori2==0 && onSegment(p1,q1,q2)) ||
            (ori3==0 && onSegment(p2,q2,p1)) ||
            (ori4==0 && onSegment(p2,q2,q1))
            )
            return true;
        return false;
    }
};

 