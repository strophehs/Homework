#include <bits/stdc++.h>
using namespace std;
char a[1000],b[1000];
int myStrcmp(char *p, char *q) {
	for (int i=0; i<max(strlen(a),strlen(b)); i++) {
		char u=p[i], v=q[i];
		if (u>v) return 1;
		else if (u<v) return -1;
	}
	return 0;
}
int main() {
	gets(a); gets(b);
	cout<<myStrcmp(a,b);
}
