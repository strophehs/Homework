struct Point {
	double x,y;
	Point(double a, double b): x(a),y(b) {
		;
	}
};
struct bRectangle {
	Point lu,rd;
};
void set(bRectangle &rec) {
	Point a,b;
	cin>>a.x>>a.y>>b.x>>b.y;
	rec.lu=Point(min(a.x,b.x),min(a.y,b.y));
	rec.rd=Point(max(a.x,b.x),max(a.y,b.y));
	if (fabs(rec.rd.y-rec.lu.y)==0.0 || fabs(rec.rd.x-rec.lu.x)==0.0) {
		a=Point(0,0);
		b=Point(1,1);
	}
	else {
		double x = fabs(rec.rd.x-rec.lu.x); // ³¤
		double y = fabs(rec.rd.y-rec.lu.y); // ¿í
	}
}
double Area(bRectangle rec) {
	double x = fabs(rec.rd.x-rec.lu.x); // ³¤
	double y = fabs(rec.rd.y-rec.lu.y); // ¿í
	return x*y;
}
void bPrint(bRectangle x) {
	cout<<Area(x);
}
