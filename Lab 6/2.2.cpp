#include <bits/stdc++.h>
using namespace std;
class CDateInfo {
	private:
		int y,m,d;
	public:
		void SetDate(int year, int month, int day) {
			y=year;
			m=month;
			d=day;
		}
		CDateInfo(int y=0, int m=0, int d=0) : y(y),m(m),d(d) {
			;
		}
		void GetDate() {
			printf("%d-%d-%d\n",y,m,d);
		}
};
int main()
{
    CDateInfo data1,data2(2011,10,10);  //�������data1��data2
    //�ֱ������Ĳ��������Ĺ��캯���ʹ�3�������Ĺ��캯���������ݳ�Ա���г�ʼ��
    //date1�����ݳ�Աδ��ʼ��ʱ������������Ĭ��ֵ2000,1,1��������ʼ����
    int y,m,d;
    cin>>y>>m>>d;   //����������ֵ
    data1.SetDate(y,m,d);  //����data1��������Ϊy��m��d
    data1.GetDate();   //��year-month-day�ĸ�ʽ��ʾdata1��������
    data2.GetDate();    //��year-month-day�ĸ�ʽ��ʾdata2��������Ϊ"2011-10-10"
    return 0;
}

