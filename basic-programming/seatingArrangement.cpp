/*
* Seating arrangement
* Date: 26th Nov 2019
* Author: Shrinath bhosale
* Problem statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/
*/

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int diff[] = {1, 3, 5, 7, 9, 11};
    const char *seats[] = {"WS", "MS", "AS", "AS", "MS", "WS"};

    while(t--) {
        int s;
        cin >> s;

        int r = (int) ceil(s/6.00);
        if(r % 2) {
            int m = 6*r;
            int i = m - s;
            cout << s + diff[i] << " " << seats[i] << endl;
        } else {
            int m = 6*(r-1) + 1;
            int i = s - m;
            cout << s - diff[i] << " " << seats[i] << endl;
        }
    }
    return 0;
}