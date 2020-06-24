// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.8
#include <iostream>
using namespace std;
int main() {
	int e1, e2; char op;
	cin>>e1>>op>>e2;
	switch(op) {
		case '+':
			cout<<e1+e2;
			break;
		case '-':
			cout<<e1-e2;
			break;
		case '*':
			cout<<e1*e2;
			break;
		case '/':
			cout<<e1/e2;
			break;
		case '%':
			cout<<e1%e2;
			break;
	}
}
