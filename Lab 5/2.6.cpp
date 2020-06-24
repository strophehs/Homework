#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
struct Node {
	int stuId, score[5];
	string name;
};
list<Node> Linklist;
void print() {
	for (list<Node>::iterator it=Linklist.begin(); it!=Linklist.end(); ++it) {
		Node p = *it;
		cout<<p.stuId<<" "<<p.name<<" ";
		for (int i=0; i<5; i++) cout<<p.score[i]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void calculate() {
	for (list<Node>::iterator it=Linklist.begin(); it!=Linklist.end(); ++it) {
		Node p=*it;
		p.score[3]=p.score[0]+p.score[1]+p.score[2];
		p.score[4]=p.score[3]/3;
		*it = p;
	}
}
bool cmp(const Node& a, const Node& b) {
	return a.score[4]>b.score[4];
}
void Sort() {
	Linklist.sort(cmp);
}
void add() {
	for (int i=0; i<5; i++) {
		Node a;
		cin>>a.stuId>>a.name;
		for (int j=0; j<3; j++) cin>>a.score[j];
		Linklist.push_back(a);
	}
}
int main() {
	add();
	calculate();
	print();
	Sort();
	print();
}
