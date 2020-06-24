// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.6
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double s,p,a,b,c;
	cin>>a>>b>>c;
	p=(a+b+c)/2.0;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<s;
}
