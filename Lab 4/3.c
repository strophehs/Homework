// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 3
#include <stdio.h>
int sum(int m, int n) {
	int res = 0;
	for (int i=m;i<=n;i++) res+=i;
	return res;
}
int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d",sum(m,n));
}
