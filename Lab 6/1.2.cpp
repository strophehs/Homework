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
    float l,w;//定义矩形的长和宽做为输入变量；
    //  cout<<"请输入矩形的长和宽："<<endl;
    cin>>l>>w;
    R.Set(l,w);	//设置矩形的长和宽
    cout<<"矩形的周长为："<<R.perimeter()<<endl;
    return 0;
}

