// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 6
#include <bits/stdc++.h>
using namespace std;
int a[12],x,p;
int main() {
	for (int i=1; i<=10; i++) cin>>a[i];
	cin>>x>>p;
	for (int i=10; i>=p; i--) a[i+1]=a[i];
	a[p]=x;
	for (int i=1; i<=11; i++) cout<<a[i]<<" ";
}
