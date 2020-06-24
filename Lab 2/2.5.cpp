// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.5
#include <bits/stdc++.h>
using namespace std;
int main() {
	for (int i=1; i<=32; i++) {
		int x=i*i;
		if (i<10 && x%10==i) cout<<x<<endl;
		else if (x%100==i) cout<<x<<endl;
	}
}
