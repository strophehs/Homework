// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.4
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,max;				//�����ĸ����ͱ���
	cin>>a>>b>>c;
	if (a>b)	max=a;
	else		max=b;		//��a��b�еĽϴ�ֵ��¼��max��
	if (c>max)	max=c;		//���c�����ֵ
	cout<<"max="<<max;	//������ֵmax
	return 0;
}

