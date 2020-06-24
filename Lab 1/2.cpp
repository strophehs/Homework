// Homework 1
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2
#include <bits/stdc++.h>
using namespace std;
int main() {
	int i,j,k;
	// Case 1
	i=7;j=8;
	i*=j+1;
	// i=63,j=8
	
	// Case 2
	i=1;j=1;k=1;
	i*=j+=k;
	// First, j+=k ->j=2
	// Then, i*=j ->i=2
	// i=2,j=2,k=1
	
	// Case 3
	i=-5;j=1;
	j-=(i-=2)+1;
	// First, i-=2 ->i=-7
	// Then, j-=(-7+1) ->j=7
	// i=-7,j=7;
	
	// Case 4
	i=1;j=i++-1;
	// First, j=i-1 ->j=0
	// Then, i++ ->i=2
	// i=2,j=0
	
	// Case 5
	i=3;j=4;k=5;
	cout<<i++-j+++--k<<endl;
	// First, --k ->k=4
	// Then, i-j+k=3 ->Output:3
	// Finally, i++,j++ ->i=4,j=5
	// i=4,j=5,k=4
	
	// Case 6
	i=1;j=2;
	k=(i+2,j+=i*4);
	// First, j+=i*4 ->j=6
	// Then, k=6
	// i=1,j=6,k=6
	
	// Case 7
	i=1;j=2;
	k=i+2,j+=i*4;
	// i=1,j=6,k=3
	
	// Case 8
	i=1;j=2;k=3;
	k=i>j>k+1;
	// i>j>k+1 is false ->k=0
	// i=1,j=2,k=0
	
	// Case 9
	i=1;j=2;
	k=i>j&&--j
	// i>j is false ->k=0
	// "--j" is not executed
	// i=1,j=2,k=0
	
	// Case 10
	i=1;j=2;
	k=i<j||j++;
	// both is correct ->k=1
	// i<j is correct, so "j++" is not executed
	// i=1,j=2,k=1
}
