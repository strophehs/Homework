// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.2
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	for (int i=1; i<=n; i++) {
		for (int j=n; j>0; j--) putchar(' ');
		for (char k='A'; k<='A'+2*(n-1); k++) putchar(k);
		putchar('\n');
	}
}
