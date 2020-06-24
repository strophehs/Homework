// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 10
#include <bits/stdc++.h>
using namespace std;
int a[10][6];
int main() {
	for (int i=1; i<=7; i++)
		for (int j=1; j<=4; j++) {
			cin>>a[i][j];
			a[i][5]+=a[i][j];
		}
	for (int i=1; i<=7; i++)
		cout<<fixed<<setprecision(2)<<(double)(a[i][5]/4.0)<<endl;
}
