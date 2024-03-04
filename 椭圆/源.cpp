#include<iostream>
using namespace std;
class Ellipse {
private:
	int x1, y1, x2, y2;
public:
	void Show() {
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	
	}
	Ellipse(int a, int b, int c, int d) {
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
	Ellipse(const Ellipse& e) {
		x1 = e.x1;
		y1 = e.y1;
		x2 = e.x2;
		y2 = e.y2;
	}
	void move(int x) {
		x1 += x;
		x2 -= x;
	}
	float Area() {
		
		return 3.1415 * (x2 - x1) * (y1 - y2) / 4;
	}
	double operator /(Ellipse& a) {
		if (a.Area() == 0) { return 0; }
		return Area() / a.Area();
	}
	~Ellipse() {
		cout << "xigou:" << ' ' << x1 << ' ' << y1 << endl;
	}
};
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int e;
	cin >> e;
	Ellipse obj1(a, b, c, d);
	Ellipse obj2(obj1);
	obj2.move(e);
	obj1.Show();
	obj2.Show();
	cout << obj1.Area() << endl;
	cout << obj2.Area() << endl;
	cout << obj1 / obj2 << endl;
}