#include<iostream>
using namespace std;
class Box {
	double length, width, height;
public:
	static int objectCount;
	Box(double a, double b, double c) {
		length = a;
		width = b;
		height = c;
		objectCount++;
	}
	friend void volumn(Box&);
};
int Box::objectCount = 0;
void volumn(Box&a) {
	cout << a.length * a.height * a.width << endl;
}
int  main()
{
	double  a, b, c;
	while (cin >> a >> b >> c) {
		Box  box(a, b, c);
		volumn(box);
	}
	//  输出对象的总数
	cout << Box::objectCount << endl;
	return  0;
}