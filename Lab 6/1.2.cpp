#include<iostream>
using namespace std;
class CRectangle
{
public:
    void Set(float a,float b)
    {
        if((a>0)&&(a<50)) length=a;
        else length=1;
        if((b>0)&&(b<50)) width=b;
        else width=1;
    }
    float perimeter()
    {
        return 2*(length+width);
    }
private:
    float length;
    float  width;
};

int main()
{
    CRectangle R;
    float l,w;//������εĳ��Ϳ���Ϊ���������
    //  cout<<"��������εĳ��Ϳ�"<<endl;
    cin>>l>>w;
    R.Set(l,w);	//���þ��εĳ��Ϳ�
    cout<<"���ε��ܳ�Ϊ��"<<R.perimeter()<<endl;
    return 0;
}

