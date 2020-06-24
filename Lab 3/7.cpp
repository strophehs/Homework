// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 7
#include <bits/stdc++.h>
using namespace std;
int x,b[100],tot;
void otb(int x) {
    if(x/2) otb(x/2);
    b[++tot]=x%2;
}
int main() {
	cin>>x; otb(x);
	for (int i=1; i<=tot; i++) cout<<b[i];
}
