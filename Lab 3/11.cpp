// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 11
#include <bits/stdc++.h>
using namespace std;
int main() {
	char a[1000]; gets(a);
	int c=0,e=0,d=0,s=0,o=0;
	for (int i=0; i<strlen(a); i++) {
		if (a[i]<0) c++;
		else if (isalpha(a[i])) e++;
		else if (isdigit(a[i])) d++;
		else if (a[i]==' ') s++;
		else o++;
	}
	printf("���Ĺ�%d��Ӣ�Ĺ�%d�����ֹ�%d,�ո�%d��������%d",c/3,e,d,s,o);
}
