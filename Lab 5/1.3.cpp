#include <iostream>
using namespace std;
int main ( )
{
	int a[5],*p;
    puts("������5��Ԫ��:");
    for(p=a;p<a+5;p++)  // p=a��ѭ����ʼǰ��ȷ��ָ��Pָ�������׵�ַ
	cin>>*p;
    puts("�����5��Ԫ��:");
    for(p=a;p!=a+5;p++)
	cout<<*p;
	return 0;
}

