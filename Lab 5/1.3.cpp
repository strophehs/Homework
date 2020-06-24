#include <iostream>
using namespace std;
int main ( )
{
	int a[5],*p;
    puts("请输入5个元素:");
    for(p=a;p<a+5;p++)  // p=a在循环开始前，确保指针P指向数组首地址
	cin>>*p;
    puts("请输出5个元素:");
    for(p=a;p!=a+5;p++)
	cout<<*p;
	return 0;
}

