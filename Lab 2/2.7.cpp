// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.7
#include <bits/stdc++.h>
using namespace std;
int main() {
	int x=0;
	double y=13.0;
	while (y<26.0) {
		x++;
		y*=1.008;
	}
	cout<<x;
}
