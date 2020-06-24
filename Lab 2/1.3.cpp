// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.3
#include <iostream>
using namespace std;
int main ( )
{
  int  i , x, y, minbs;
  cout<<"输入2个正整数：";
  cin>>x>>y;
  for ( i=x*y;  i>=x;  i-=y )
    if(i%x==0)
      minbs = i;
  cout<<"minbs ="<<minbs;
  return 0;
}

