// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 4
#include <bits/stdc++.h>
using namespace std;
int a[11],x;
int main() {
	for (int i=1; i<=10; i++) cin>>a[i];
	cin>>x;
	sort(a+1,a+11);
	int pos = lower_bound(a+1,a+11,x)-a;
	if (pos==11) cout<<"no";
	else if (a[pos]==x) cout<<"yes";
	else cout<<"no";
}
