#include<iostream>
using namespace std;
class  girl
{
private:
    char  name;
    int  age;
public:
    girl(char n, int d)     //���캯��
    {
        name= n;
	    age=d;
	}
	friend void display(girl  &x);  //������Ԫ����
};
void  display(girl &x)         //���ⶨ�� ��Ԫ����
{
    cout<<"Girl's name is :"<<x. name<<", age is :"<<x.age<<endl;
    //girl�����Ԫ�����ܷ���girl������˽�г�Ա
}
int  main( )
{
    girl  e('z',18);
    display(e);          //������Ԫ����
    return 0;
}

