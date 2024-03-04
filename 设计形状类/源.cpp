#include<iostream>
using namespace std;

const double pi = 3.14;
class Shape {
public:
	static int count;
	virtual void area() = 0;
	Shape() {
		count++;
	}
};
int Shape::count = 0;

class Rectangle:public Shape {
private:
	float x, y;
public:
	virtual  void area() {
		cout << x * y << endl;
		}
	Rectangle(float a,float b):Shape(){
		x = a;
		y = b;
	}
};
class Circle :public Shape {
public:
	float r;
	virtual void area() {
		cout << pi * r * r << endl;
	}
	Circle(float c) :Shape() {
		r = c;
	}
};
class Ellipse :public Circle {
private:
	float b;
public:
	virtual void area() {
		cout << b*r*pi<< endl;
	}
	Ellipse(float c, float d) :Circle(c) {
		b = d;
	}
};
int  main()
{
	float  x, y, r, b;
	cin >> x >> y >> r >> b;
	Rectangle  rect(x, y);
	rect.area();
	Circle  circle(r);
	circle.area();
	Ellipse  ellipse(r, b);
	ellipse.area();
	cout << Shape::count << endl;
	return  0;
}