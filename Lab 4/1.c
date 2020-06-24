// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 1
#include <stdio.h>
#include <math.h>
const double pi = acos(-1);
double r,h;
void solve1() {
	if (r>0.0 && h>0.0) printf("均为正数\n");
	else printf("不是均为正数\n");
}
void solve2() {
	double V = pi*r*r*h;
	printf("V=%lf\n",V);
}
void solve3() {
	double S = pi*r*2.0*h+pi*r*r*2.0;
	printf("S=%lf\n",S);
}
int main() {
	scanf("%lf%lf",&r,&h);
	solve1(); solve2(); solve3();
}
