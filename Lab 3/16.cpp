// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 16
#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[1001]; gets(s);
	int pos1 = 0, pos2 = strlen(s)-1;
	while (s[pos1]==' ') pos1++;
	while (s[pos2]==' ') pos2--;
	for (int i=pos1; i<=pos2; i++) putchar(s[i]);
}
