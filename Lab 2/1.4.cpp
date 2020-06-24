// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.4
#include <iostream>
using namespace std;
int main ( )
{
  int  n; //台阶数
  n = 1;
  while ( 1 )
  {
       if(n%2==1 && n%3==2 && n%4==3 && n%5==4 && n%6==5 && n%7==0)
	   {     cout<<"台阶数至少为"<< n;
            break;
       }
    n++;
  }
  return 0;
}

