// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.5
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  double x,y;
  cout<<"ÊäÈëx:";
  cin>>x;
  if(x>0)
    y=x+1;
  else if(x>-3)
    y=x-1;
  else if(x>=-7)
    y=x;
  cout<<fixed<<setprecision(1)<<y;
  return 0;
}

