// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.3
#include <iostream>
using namespace std;
int main() {
	int a,b=0,c;
	cin>>a; c=a;
	while (a) {
		int t=a%10;
		a/=10;
		b+=t*t*t;
	}
	if (b==c) cout<<"yes";
	else cout<<"no";
}
