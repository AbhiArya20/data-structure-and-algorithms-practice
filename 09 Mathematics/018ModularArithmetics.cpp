#include<bits/stdc++.h>
using namespace std;

// Modular Arithematic

/*
    n = 1e9+7 (1e9+7 is a prime number)

    let
        A = Divident
        B = Divisor
        Q = Quotient
        R = Remainder
    then 
        A = (B*Q) + R
    
    Properties of Modular Arithemetic
        1->     (a%n == b%n) => a ≡ b%n  - if (a-b) is mutiple of (n)
        2->     (a%n == b && b%n==c) => ba ≡ b%n 
        3->     (a+b)%n == (a%n + b%n)%n
        4->     (a*b)%n == (a%n * b%n)%n
        5->     (a-b)%n == (a%n - b%n)%n == (a-b+n)%n 
        6->     (a/b)%n == (a*pow(b,-1))%n == (a*pow(b,n-2))%n == (a%n * pow(b,n-2)%n)%n - if(n == prime)
        7->     pow(a,b)%n = (a*a*a*a.....a*a*a...b-times)%n if(n>b)
        8->     pow(a,b)%n = pow(a,b%(n-1)) if(b>n)


*/