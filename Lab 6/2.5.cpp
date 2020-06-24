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
    cin>>x1>>y1>>x2>>y2;    //����4�����ݣ��ֱ��ʾ�������������������ʵ�����鲿
    Imaginary imag1(x1,y1),imag2(x2,y2);    //��x1��y1����Imaginary�����imag1
    Add(imag1,imag2);   //������Ԫ��������������֮�ͣ���a��bi�ĸ�ʽ��ʾ��������a��b��Ϊʵ����
    Sub(imag1,imag2);   //����������֮���ʾ������
    return 0;
}

