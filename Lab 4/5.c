// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100000
int in_cir(double x,double y) {
	return x*x+y*y<=1.0;
}
int main() {
    double x,y;
    int num=0;
    srand((unsigned)time(NULL));
    for (int i=0;i<N;i++) {
        x=rand()*1.0/RAND_MAX;
        y=rand()*1.0/RAND_MAX;
        if (in_cir(x,y)) num++;
    }
    printf("pi approximately equals to %lf\n",num*4.0/N);
}
