#include <bits/stdc++.h>
using namespace std;
int a[10];
int tot1,tot2,tot3,sum1,sum2;
int main() {
	for (int i=0; i<10; i++) cin>>a[i];
	int *p;
	for (p=a; p<=a+9; p++) {
		if (*p>0) tot1++,sum1+=*p;
		else if (*p<0) tot2++,sum2+=*p;
		else tot3++;
	}
	printf("%d positive numbers\n%d negative numbers\n%d zero numbers\nThe sum of all positive numbers is %d.\nThe sum of all negative numbers is %d.",tot1,tot2,tot3,sum1,sum2);
}
