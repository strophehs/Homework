#include<iostream>
using namespace std;
class  girl
{
private:
    char  name;
    int  age;
public:
    girl(char n, int d)     //构造函数
    {
        name= n;
	    age=d;
	}
	friend void display(girl  &x);  //声明友元函数
};
void  display(girl &x)         //类外定义 友元函数
{
    cout<<"Girl's name is :"<<x. name<<", age is :"<<x.age<<endl;
    //girl类的友元函数能访问girl类对象的私有成员
}
int  main( )
{
    girl  e('z',18);
    display(e);          //调用友元函数
    return 0;
}

