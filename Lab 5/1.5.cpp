#include<iostream>
using namespace std;
int main ( )
{
	int i;  char s[10], *p;
	for (i=0; i<9; i++)
	{
		s[i]=getchar( ); //�Ӽ��̻�ȡ�ַ�����ֵ������s��ֱ�������س����з�����
		if (s[i]=='\n')
			break;
	}
	s[i]='\0';
	p=s;
	while (*p)
	   putchar (*p++);
    return 0;
}

