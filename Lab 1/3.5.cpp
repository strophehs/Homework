// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.5
#include <iostream>
using namespace std;
const int standard[5] = {90,80,70,60,0};
const char lvl[6] = "ABCDE";
int main() {
	int x; cin>>x;
	for (int i=0; i<5; i++)
		if (x>=standard[i]) {
			cout<<lvl[i];
			break;
		}
}
