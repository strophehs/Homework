// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 12
#include <stdio.h>
int sum(int x) {
	if (x==0) return x;
	else return x + sum(x-1);
}
int main() {
	int n;
	scanf("%d",&n);
	printf("%d",sum(n));
}
