struct aRectangle {
	double a, b;
};
void set(aRectangle &x) {
	double u, v;
	cin>>u>>v;
	if (u>0 && u<50) x.a=u;
	else x.a=1;
	if (v>0 && v<50) x.b=v;
	else x.b=1;
}
double Perimeter(aRectangle x) {
	return 2.0*x.a + 2.0*x.b;
}
void bPrint(aRectangle x) {
	cout<<Perimeter(x);
}
