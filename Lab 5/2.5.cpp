const int MEM = 5;
const int ML = 10;
struct stu {
	char StuId[ML];
	char StuName[ML];
	int Chn, Mat, Eng, Ave, Sum;
} student[MEM];
void Inpute() {
	for (int i=0; i<MEM; i++) {
		scanf("%s %s %d %d %d", student[i].StuId, student[i].StuName, student[i].Chn, student[i].Mat, student[i].Eng);
	}
}
void calculate() {
	for (int i=0; i<MEM; i++) {
		student[i].Sum = student[i].Chn + student[i].Mat + student[i].Eng;
		student[i].Ave = student[i].Sum / 3.0;
		printf("%s %s %d %d %d %d %d\n", student[i].StuId, student[i].StuName, student[i].Chn, student[i].Mat, student[i].Eng, student[i].Sum, student[i].Ave);
	}
}
void qsort(int l,int r) { // Use qsort(0,4)
    int mid=student[(l+r)/2].Ave;
    int i=l,j=r;
    do{
        while(student[i].Ave<mid) i++;
        while(student[j].Ave>mid) j--;
        if(i<=j)
        {
			stu temp;
			temp = student[i];
			student[i]=student[j];
			student[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
