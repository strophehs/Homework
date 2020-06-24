// Homework 3
// Author: Huang Shen, Class 1901
// Student ID: 2019310220123
// Problem 3
#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
	a=a^b;
	b=a^b;
	a=a^b;
}

void selectionSort(int a[], int length);
void swapSort(int a[], int length);
void bubbleSort(int a[], int length);

int a[11];
int main() {
	for (int i=1; i<=10; i++) {
		int x; cin>>x;
		if (i%2==0) a[i/2-1]=x;
	}
	int op; cin>>op;
	switch(op) {
		case 1: selectionSort(a,5);break;
		case 2: swapSort(a,5);break;
		case 3: bubbleSort(a,5);break;
	}
	for (int i=0; i<5; i++) cout<<a[i]<<" ";
}
void selectionSort(int a[], int length) {
    int pos;
    for (int i=0; i<length-1; i++) {
    	pos=i;
    	for (int j=i+1; j<length; j++)
			if (a[pos]>a[j]) pos=j;
		if (pos!=i) swap(a[pos],a[i]);
    }
}
void swapSort(int a[], int length) {
	for (int i=0; i<length-1; i++)
		for (int j=i+1; j<length; j++)
			if (a[i]>a[j]) swap(a[i],a[j]);
}
void bubbleSort(int a[], int length) {
    for (int i=0; i<length-1; i++)
        for (int j=0; j<length-1-i; j++)
            if (a[j]>a[j+1])
				swap(a[j],a[j+1]);
}

