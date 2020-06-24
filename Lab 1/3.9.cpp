// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.9
#include <iostream>
using namespace std;
int main() {
	double x,y;
	cin>>x;
	if (x<0) y=0;
	else if (x<=10) y=x;
	else if (x<=20) y=10;
	else y=-x/2.0+20;
	cout<<y;
}
