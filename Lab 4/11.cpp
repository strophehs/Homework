// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 11
#include <stdio.h>
#include <limits.h>
void f(int a[], int n, int &max, int &min) {
	for (int i=0; i<n; i++) {
		if (a[i]<min) min=a[i];
		if (a[i]>max) max=a[i];
	}
	printf("max=%d,min=%d",max,min);
}
int main() {
	int n, a[100001], maxn=INT_MAX+1, minn=INT_MAX;
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",a+i);
	f(a,n,maxn,minn);
}
