// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.8
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c;
	while (cin>>a>>b>>c) {
		if (a+b<=c || a+c<=b || b+c<=a) continue;
		int p=(a+b+c)/2;
		double area = sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<area;
		return 0;
	}
}
