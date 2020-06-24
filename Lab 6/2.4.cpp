#include <bits/stdc++.h>
using namespace std;
class Calculator {
	private:
		float a,b;
	public:
		Calculator(float a, float b):a(a),b(b) {
			;
		}
		void add() {
			printf("%f+%f=%f\n",a,b,a+b);
		}
		void subtract() {
			printf("%f-%f=%f\n",a,b,a-b);
		}
		void multiply() {
			printf("%f*%f=%f\n",a,b,a*b);
		}
		void divide() {
			printf("%f/%f=%f\n",a,b,a/b);
		}
};
int main( )
{
    float  a, b;
	cin>>a>>b; //从键盘输入运算数a、b
	Calculator  cal( a , b );   //用a和b初始化创建的Calculator类对象cal
	cal.add( ); //计算a+b并显示结果
	cal.subtract( );
	cal.multiply( );
	cal.divide( );
	return 0;
}

