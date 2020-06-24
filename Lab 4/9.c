// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 9
#include <stdio.h>
void bin(int n, char s[]) {
	int t=0;
	while (n) {
		if (n&1) s[t]='1';
		else s[t]='0';
		t++; n>>=1;
	}
	for (int i=t-1; i>=0; i--) putchar(s[i]);
}
int main() {
	int n;
	scanf("%d",&n); char s[32];
	bin(n,s);
}
