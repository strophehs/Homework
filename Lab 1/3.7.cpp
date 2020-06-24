// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.7
#include <iostream>
using namespace std;
int main() {
	int x,y,sum=0;
	cin>>x>>y; int m=min(x,y);
	sum=m>=70?90*m:110*m;
	x-=m,y-=m;
	sum+=70*x+60*y;
	cout<<sum;
}
