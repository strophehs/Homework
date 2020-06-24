// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.2
#include <iostream>
using namespace std;
int main() {
	int a,b,c,d,e,f;
	cin>>a>>b>>c;
	d=min(min(a,b),c);
	f=max(max(a,b),c);
	e=a+b+c-d-f;
	cout<<d<<" "<<e<<" "<<f;
}
