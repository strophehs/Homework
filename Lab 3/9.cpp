// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 9
#include <bits/stdc++.h>
using namespace std;
void solve1();
void solve2();
int n,a[6][6];
int main() {
	cin>>n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) cin>>a[i][j];
	solve1();
	solve2();
}
void solve1() {
	int sum=0;
	for (int i=1; i<=n; i++) sum+=a[i][i]+a[i][n-i+1];
	if (n%2==1) sum-=a[n/2+1][n/2+1];
	cout<<sum<<endl;
}
void solve2() {
	int sum=0;
	for (int i=2; i<=n; i+=2)
		for (int j=2; j<=n; j+=2) sum+=a[i][j];
	cout<<sum<<endl;
}
