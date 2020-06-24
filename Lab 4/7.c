// Homework 4
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 7
#include <stdio.h>
int n; double a[1001][3],aver[3];
void f(double a[][3],int n,double aver[3]) {
	int sum[3] = {0};
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
			sum[j]+=a[i][j];
	for (int i=0; i<3; i++)
		aver[i]=sum[i]/(double)n,
		printf("Subject %d's average score is %lf\n", i, aver[i]);
}
int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
			scanf("%lf",&a[i][j]);
	f(a,n,aver);
}
