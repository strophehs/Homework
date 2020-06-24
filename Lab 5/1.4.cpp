#include<iostream>
using namespace std;
int main ( )
{
	int a[ ]={1,2,3,4,5},*p;
    for (p=a+4;p>=a;p--)
	  cout<<*p;
    return 0;
}

