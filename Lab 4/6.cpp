// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 6
#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
bool search(int x) {
	int t = lower_bound(a+1,a+n+1,x)-a;
	return a[t]==x;
}
int main() {
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int tmp; cin>>tmp;
	if (search(tmp)) cout<<"yes";
	else cout<<"no";
}
