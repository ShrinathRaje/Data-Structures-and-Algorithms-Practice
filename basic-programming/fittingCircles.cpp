/*
* Fitting Circles
* Date: 7th Dec 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/fitting-circles-c00a5be3/description/
*/

#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int l, b;
        cin >> l >> b;
        
        if(l >= b)
            cout << l/b << "\n";
        else
            cout << b/l << "\n";
    }
    return 0;
}