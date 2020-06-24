#include<iostream>
using namespace std;
int main ( )
{
	int i;  char s[10], *p;
	for (i=0; i<9; i++)
	{
		s[i]=getchar( ); //从键盘获取字符串赋值给数组s，直到遇到回车换行符结束
		if (s[i]=='\n')
			break;
	}
	s[i]='\0';
	p=s;
	while (*p)
	   putchar (*p++);
    return 0;
}

