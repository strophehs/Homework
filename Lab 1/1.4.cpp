// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.4
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,max;				//声明四个整型变量
	cin>>a>>b>>c;
	if (a>b)	max=a;
	else		max=b;		//将a和b中的较大值记录在max中
	if (c>max)	max=c;		//如果c是最大值
	cout<<"max="<<max;	//输出最大值max
	return 0;
}

