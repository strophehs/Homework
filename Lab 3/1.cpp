// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 1
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[11],b[10];
	for (int i=1; i<=10; i++) {
		cin>>a[i];
		if (i!=1) {
			b[i-1]=a[i]-a[i-1];
			cout<<b[i-1];
			if (i%3==1) cout<<endl;
			else cout<<" ";
		}
	}
}
