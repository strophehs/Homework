// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 13
#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[1000]; char ch;
	gets(s); cin>>ch;
	for (int i=0; i<=strlen(s); i++) {
		if (s[i]==ch) continue;
		cout<<s[i];
	}
}
