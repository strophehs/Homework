// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 4
#include <stdio.h>
#include <math.h>
#define RANGE 6
int fac[20];
void init_fac(int n) {
	fac[0]=1;
	for (int i=1; i<=n; i++) fac[i]=fac[i-1]*i;
}
double sin(double x) {
	double sinx = 0.0;
	for (int i=1; i<=RANGE; i++) {
		int t = 2*i-1;
		int symb = (i%2?1:-1);
		sinx += symb * pow(x,t) / fac[t];
	}
	return sinx;
}
int main() {
	init_fac(19);
	double x; scanf("%lf",&x);
	printf("%lf",sin(x));
}
