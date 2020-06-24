// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 15
#include <bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	cin>>a>>b;
	if (a>b) cout<<"大于";
	else if (a==b) cout<<"等于";
	else if (a<b) cout<<"小于";
}
int my_strcmp(char a[], char b[]) { // 0->smaller 1->larger 2->equal
	int len1=strlen(a),len2=strlen(b);
	if (len1!=len2) return len1>len2;
	for (int i=0; i<len1; i++) {
		if (a[i]==b[i]) continue;
		else return a[i]>b[i];
	}
	return 2;
}
