#include <bits/stdc++.h>
using namespace std;
class Student {
	private:
		char* name;
		int sex;
		unsigned age;
	public:
		void SetName(char *x) {
			name = x;
		}
		void SetGender(int gender) {
			sex = gender;
		}
		void SetAge(unsigned y) {
			age = y;
		}
		void GetName(char* x) {
			x = name;
		}
		int GetGender() {
			return sex;
		}
		int GetAge() {
			return age;
		}
};
int main()
{
    Student Zhang_San;  //����Student�����Zhang_San
    char *chOne;
    int iSex;
    unsigned iOld;
    chOne=new char[11]; //������̬�ַ������������������ָ��chOneָ�������
    cin>>chOne; //���������������chOne��ָ��Ķ�̬�ַ�������
    cin>>iSex;  //�����Ա�����1��ʾ�Ա�Ϊ"��"������0��ʾ�Ա�Ϊ"Ů"
    cin>>iOld;  //��������
    Zhang_San.SetName(chOne);   //��������������ö���Zhang_San������ʾ���������ݳ�Ա
    Zhang_San.SetGender(iSex);  //���ö���Zhang_San������ʾ�Ա�����ݳ�Ա
    Zhang_San.SetAge(iOld); //���ö���Zhang_San������ʾ��������ݳ�Ա
    cout<<endl;
    Zhang_San.GetName(chOne);   //����GetName(char *)��Ա����������Zhang_San��ʾ���������ݳ�Աֵ
                                //��ŵ�chOne��ָ��Ķ�̬�ַ�������
    cout<<"Zhang_San's name is "<<chOne<<endl;  //��ʾ����
    cout<<"Zhang_San's gender is "<<Zhang_San.GetGender()<<endl;   //��ʾ�Ա�1���У���0��Ů��
    cout<<"Zhang_San's age is "<<Zhang_San.GetAge()<<endl;  //��ʾ����
    delete []chOne;
    return 0;
}
