#include <iostream>
using namespace std;
int main ( )
{
	int i,a[5],*p;
    puts("������5��Ԫ��:");
    p=a;
    //(1)��ѭ����ʼǰ��ȷ��ָ��Pָ�������׵�ַ
    for(i=0;i<5;i++)
    cin>>*p,p++;
    //(2)��ָ������������Ԫ��
    puts("�����5��Ԫ��:");
    p=a;
    for(i=0;i<5;i++)
    cout<<*p<<endl,p++;
	//(3)��ָ������������Ԫ��
	return 0;
}

