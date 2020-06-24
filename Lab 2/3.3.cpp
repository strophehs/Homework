// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.3
#include <bits/stdc++.h>
using namespace std;
const int fac[11]={0,1,2,6,24,120,720,5040,40320,362880,3628800};
int main() {
	double s=0.0;
	for (int i=1; i<=10; i++)
		s+=1.0/(double)fac[i];
	cout<<s;
}
