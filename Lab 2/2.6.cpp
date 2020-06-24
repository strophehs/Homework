// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.6
#include <bits/stdc++.h>
using namespace std;
int main() {
	for (int i=1; i<=50; i++)
		for (int j=1; j<=50; j++)
			if (50-i-j>0)
				if (10*i+5*j+1*(50-i-j)==100)
					printf("%d张10元，%d张5元，%d张1元\n",i,j,50-i-j);
}
