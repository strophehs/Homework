// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 5
#include <bits/stdc++.h>
using namespace std;
int a[11],x;
int main() {
	for (int i=1; i<=10; i++) cin>>a[i];
	cin>>x; int pos=0;
	for (int i=1; i<=10; i++)
		if (a[i]==x) {pos=i; break;}
	if (pos==0) cout<<"数组中无该数据";
	else for (int i=1; i<=10; i++) {
		if (i==pos) continue;
		else cout<<a[i]<<" ";
	}
}
