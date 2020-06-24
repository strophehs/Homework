// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 2
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[11],maxn=INT_MAX+1,minn=INT_MAX,maxi,mini;
	for (int i=1; i<=10; i++) {
		cin>>a[i];
		if (a[i]>maxn) maxn=a[i],maxi=i;
		if (a[i]<minn) minn=a[i],mini=i;
	}
	cout<<maxn<<" "<<maxi<<endl<<minn<<" "<<mini;
}
