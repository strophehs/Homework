#include<iostream>
#include<cmath>
using namespace std;
class point
{
public:
    point(float a,float b) { x=a; y=b; }
    float Distance(point &p)
    {
        float dx=fabs(x-p.x);
        float dy=fabs(y-p.y);
        return (float)sqrt(dx*dx+dy*dy);
	}
private:
    float x,y;
};

int main()
{
    point p1(2,3),p2(32,43);
    cout<<p1.Distance(p2)<<endl;
    return 0;
}

