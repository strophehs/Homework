#include <iostream>
using namespace std;
int main ( )
{
	int i,a[5],*p;
    puts("请输入5个元素:");
    p=a;
    //(1)在循环开始前，确保指针P指向数组首地址
    for(i=0;i<5;i++)
    cin>>*p,p++;
    //(2)用指针变量输入各个元素
    puts("请输出5个元素:");
    p=a;
    for(i=0;i<5;i++)
    cout<<*p<<endl,p++;
	//(3)用指针变量输出各个元素
	return 0;
}

