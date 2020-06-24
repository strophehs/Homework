// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.5
#include<bits/stdc++.h>
using namespace std;
int main(){
	double money=0;
	for(int i=1;i<=5;i++){
		money=(money+1000)/pow(1.0032,12);
	}
	cout<<money;
	return 0;
}
