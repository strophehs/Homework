// Homework 2
// Author: Huang Shen, class 1901
// Student ID: 2019310220123
// Problem 2.2
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m,fac[1000005];
void init(int x) {
	fac[0]=1;
	for (int i=1; i<=x; i++) fac[i]=fac[i-1]*i%mod;
}
int qpow(int b, int p) {
	int res=1;
	while (p) {
		if (p%2==1) res=res*b%mod;
		p>>=1; b=b*b%mod;
	}
	return res%mod;
}
int main() {
	cin>>n>>m;
	init(m);
	if (m<n) cout<<"0.00";
	else cout<<fixed<<setprecision(2)<<fac[m]*qpow(fac[n],mod-2)*qpow(fac[m-n],mod-2);
	//m!/(n!(m-n)!)
}
