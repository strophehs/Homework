// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.1
#include<iostream>
using namespace std;
int main()
{
  int x,gw,sw,bw;
  cin>>x;
  gw=x%10;
  bw=x/100;
  sw=(x-bw*100-gw)/10;
  cout<<"sum is:"<<gw+sw+bw;
  return 0;
}
