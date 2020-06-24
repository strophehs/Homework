// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 8
#include <stdio.h>
int f(char s[]) {
	int len = strlen(s);
	for (int i=0; i<len/2; i++)
		if (s[i]!=s[len-i-1]) return 0;
	return 1;
}
int main() {
	char s[1001]; gets(s);
	if (f(s)) printf("yes");
	else printf("no");
}
