// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 8
#include <bits/stdc++.h>
using namespace std;
int a[6][5],b[5][6];
int main() {
	for (int i=1; i<=4; i++)
		for (int j=1; j<=5; j++) {
			cin>>a[i][j];
			b[j][i]=a[i][j];
		}
	for (int i=1; i<=5; i++) {
		for (int j=1; j<=4; j++) cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
