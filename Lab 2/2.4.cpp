// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.4
#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
	int a=x%10,x/=10;
	int b=x%10,x/=10;
	int c=x%10;
	return a*a*a+b*b*b+c*c*c==100*c+10*b+c;
}
int main() {
	for (int i=100; i<=999; i++)
		if (check(i)) cout<<i<<endl;
}
