// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
int x,y,z,n,tot; char op;
double cal(int x) {return (double)x/(double)n*100.0;}
int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		srand((unsigned)time(NULL));
		x=rand()%MAX, y=rand()%MAX, z=rand()%4;
		switch(z) {
			case 0: op='+';break;
			case 1: op='-';break;
			case 2: op='*';break;
			case 3: op='/';break;
		}
		printf("%d%c%d=",x,op,y);
		scanf("%d",&z);
		switch(op) {
			case '+': if(x+y==z)tot++; break;
			case '-': if(x-y==z)tot++; break;
			case '*': if(x*y==z)tot++; break;
			case '/': if(x/y==z)tot++; break;
		}
	}
	printf("Correction rate is %.2lf%%",cal(tot));
}
