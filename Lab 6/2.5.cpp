#include <bits/stdc++.h>
using namespace std;
class Imaginary {
	private:
		float x,y;
		void print() {
			cout<<x<<(y>=0?'+':'-')<<(y>=0?y:-y)<<"i";
		}
	public:
		Imaginary(float x=0, float y=0):x(x),y(y) {
			;
		}
		friend void Add(Imaginary a, Imaginary b);
		friend void Sub(Imaginary a, Imaginary b);
};
void Add(Imaginary a, Imaginary b) {
	Imaginary p;
	p.x=a.x+b.x;
	p.y=a.y+b.y;
	p.print();
	cout<<endl;
}
void Sub(Imaginary a, Imaginary b) {
	Imaginary p;
	p.x=a.x-b.x;
	p.y=a.y-b.y;
	p.print();
	cout<<endl;
}
int main()
{
    float x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;    //输入4个数据，分别表示进行运算的两个复数的实部和虚部
    Imaginary imag1(x1,y1),imag2(x2,y2);    //用x1、y1创建Imaginary类对象imag1
    Add(imag1,imag2);   //调用友元函数求两个复数之和，按a±bi的格式显示运算结果（a和b均为实数）
    Sub(imag1,imag2);   //求两个复数之差并显示运算结果
    return 0;
}

