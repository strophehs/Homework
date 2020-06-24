// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 3.4
#include <iostream>
#include <cstring>
using namespace std;
char s[5];
int main() {
	scanf("%s",s+1);
	int l = strlen(s+1);
	for (int i=1; i<l/2; i++) {
		if (s[i]==s[l-i+1]) continue;
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}
