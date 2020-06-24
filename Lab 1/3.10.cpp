// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.10
#include <iostream>
using namespace std;
int main() {
	cout<<"*****Time*****\n1 morning\n2 afternoon\n3 night\nPlease enter yout choice:";
	int op; cin>>op;
	switch(op) {
		case 1:
			cout<<"morning";
			break;
		case 2:
			cout<<"afternoon";
			break;
		case 3:
			cout<<"night";
			break;
		default:
			cout<<"Selection error!";
			break;
	}
}
