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
	cin>>a>>b; //�Ӽ�������������a��b
	Calculator  cal( a , b );   //��a��b��ʼ��������Calculator�����cal
	cal.add( ); //����a+b����ʾ���
	cal.subtract( );
	cal.multiply( );
	cal.divide( );
	return 0;
}

