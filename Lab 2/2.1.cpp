// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.1
#include <bits/stdc++.h>
using namespace std;
int main() {
	double sum=0.0;
	for (int i=1; i<=25; i++)
		sum+=1.0/(double)((i*2)*(i*2-1));
	cout<<fixed<<setprecision(3)<<sum;
}
