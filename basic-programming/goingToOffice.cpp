/*
* Going to office
* Date: 27th Nov 2019
* Author: Shrinath bhosale
* Problem statement: https://www.hackerearth.com/practice/basic-programming/operators/basics-of-operators/practice-problems/algorithm/going-to-office-e2ef3feb/description/
*/

#include<iostream>

using namespace std;

int main() {
	long d, oc, ok, ov, cs, cb, cm, ck;
	cin >> d >> oc >> ok >> ov >> cs >> cb >> cm >> ck;

	long oct = (ok >= d) ? oc: oc + (d-ok)*ov;
	long cct = cb + (d/cs)*cm + d*ck;

	cout << ((oct <= cct) ? "Online Taxi" : "Classic Taxi");
	return 0;
}
