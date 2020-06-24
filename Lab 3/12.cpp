// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 12
#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[1000];
	gets(s);
	int len = strlen(s);
	bool isPalindromic = 0;
	for (int i=0; i<len/2+1; i++)
		if (s[i]!=s[len-i-1]) {
			isPalindromic = 1;
			break;
		}
	if (isPalindromic) cout<<"no";
	else cout<<"yes";
}
