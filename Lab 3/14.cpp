// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 14
#include<bits/stdc++.h>
using namespace std;
int main() {
	char str[1001],t1,t2;
	gets(str);
	int L=strlen(str);
	for (int i=0;i<L/2;i=i+2) {
		t1=str[i];t2=str[i+1];
		str[i] = str[L-2-i]; str[i+1]=str[L-1-i];
		str[L-2-i]=t1; str[L-1-i]=t2;
	}
	printf("%s",str);
}
