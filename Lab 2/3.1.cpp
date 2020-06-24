// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.1
#include <bits/stdc++.h>
using namespace std;
int main() {
	double x=100.0,s=0.0;
	for (int i=1; i<=8; i++) s+=x,x/=2.0,s+=x;
	cout<<s-x<<endl<<x;
}
