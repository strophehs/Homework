// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 14
#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int main() {
	char s[1001];
	gets(s); int len=0,t=strlen(s),maxlen=0;
	for (int i=0; i<t; i++) {
		if (s[i]==' ' || s[i]==',') maxlen=max(maxlen,len),len=0;
		else len++;
	}
	maxlen=max(maxlen,len);
	printf("%d",maxlen);
}
