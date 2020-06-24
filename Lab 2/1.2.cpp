// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.2
#include <iostream>
using namespace std;
int main ( )
{
  int  i , n;
 double sum = 0.0 ;
  cout<<"输入一个正整数:";
  cin>>n;
  for ( i=1;  i<=n;  i+=2 )
  	sum +=  1.0/(double)i;
  cout<<"sum ="<<sum;
  return 0;
}

