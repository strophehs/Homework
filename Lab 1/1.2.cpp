// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 1.2
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  double cash,total;
  int n;
  cin>>cash>>n;
  total=pow(103.05*cash,n);
  cout<<"本利之和为:"<<total;
  return 0;
}

