// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 10
#include <stdio.h>
#include <string.h>
int len1, len2, ne[100005];
void getnext(char s[]) {
	for (int i=2, j=0; i<=len2; i++) {
		while (j && s[i]!=s[j+1]) j=ne[j];
		if (s[i]==s[j+1]) j++;
		ne[i]=j;
	}
}
int findstr(char s[], char t[]) { //kmp
	for (int i=1,j=0; i<=len1; i++) {
		while (j && s[i]!=t[j+1]) j=ne[j];
		if (s[i]==t[j+1]) j++;
		if (j==len2) return 1;
	}
	return 0;
}
int main() {
	char a[100005], b[100005];
	scanf("%s%s",a+1,b+1);
	len1=strlen(a+1); len2=strlen(b+1);
	getnext(b);
	if (findstr(a,b)) printf("yes");
	else printf("no");
}
