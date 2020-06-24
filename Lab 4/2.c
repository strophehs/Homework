// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 2
#include <stdio.h>
int a,b;
int gcd(int a, int b) {return b==0?a:gcd(b,a%b);}
int main() {
	while (scanf("%d%d",&a,&b)) {
		int _gcd = gcd(a,b);
		printf("GCD=%d\n",_gcd);
		printf("LCM=%d\n",a*b/_gcd);
	}
}
