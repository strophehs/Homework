#include<iostream>
#include<cmath>
using namespace std;
class CRectangle
{
public:
    CRectangle(float Rx1=0,float Ry1=0, float Rx2=1,float Ry2=1);
private:
    //确定直线的两点的坐标
    float x1,y1,x2,y2;
};
CRectangle::CRectangle(float Rx1 ,float Ry1, float Rx2,float Ry2)
{
    if (Rx1==Rx2 || Ry1==Ry2) //两点的横坐标或纵坐标的值相等，则不能构成矩形
    {
        x1=y1=0;
        x2=y2=1;
        cout<<"不能构成矩形! "<<endl;
    }
    else
    {
        x1=Rx1; x2=Rx2; y1=Ry1; y2=Ry2;		//初始化数据成员x1,y1,x2,y2
        cout<<"可以构成矩形! "<<endl;
    }
}

int main()
{
    CRectangle R1(1,3,5,6);
    CRectangle R2(1,3,1,6);
    return 0;
}

