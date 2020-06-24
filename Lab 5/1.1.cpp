#include <iostream>
using namespace std;
int main ( )
{
	int *a, *b, *c, num, x, y, z;
	a=&x;   b=&y;   c=&z;
	puts("输入3个整数：");
	cin>>*a>>*b>>*c;
	cout<<a<<b<<c;
	num=*a;
	if(*a>*b)  num=*b;
	if(num>*c)  num=*c;
	cout<<"输出最小整数:"<<num;
	return 0;
}

