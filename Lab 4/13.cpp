// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 13
#include <stdio.h>
int getmax(int a, int b, int c) {
	return a>b&&a>c?a:b>a&&b>c?b:c;
}
double getmax(double a, double b, double c) {
	return a>b&&a>c?a:b>a&&b>c?b:c;
}
int main() {
	int a,b,c; double d,e,f;
	scanf("%d%d%d%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	printf("max1=%d,max2=%lf\n",getmax(a,b,c),getmax(d,e,f));
}
