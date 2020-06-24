#include <bits/stdc++.h>
using namespace std;
class point {
	public:
		friend float Distance(point a, point b);
		point(float a, float b): x(a), y(b) {
			;
		}
	private:
		float x,y;
};
float Distance(point a, point b) {
	double dx=fabs(a.x-b.x);
	double dy=fabs(a.y-b.y);
	return sqrt(dx*dx+dy*dy);
}
int  main()
{
  float p1_x,p1_y,p2_x,p2_y;
  //输入四个点
  cin>>p1_x>>p1_y>>p2_x>>p2_y;
  point p1(p1_x,p1_y),p2(p2_x,p2_y);
  cout<<Distance(p1,p2)<<endl;
  return 0;
}

