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
    CDateInfo data1,data2(2011,10,10);  //定义对象data1和data2
    //分别调用类的不带参数的构造函数和带3个参数的构造函数对其数据成员进行初始化
    //date1的数据成员未初始化时，其年月日用默认值2000,1,1来继续初始化。
    int y,m,d;
    cin>>y>>m>>d;   //输入年月日值
    data1.SetDate(y,m,d);  //设置data1的年月日为y，m，d
    data1.GetDate();   //按year-month-day的格式显示data1的年月日
    data2.GetDate();    //按year-month-day的格式显示data2的年月日为"2011-10-10"
    return 0;
}

