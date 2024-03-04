#include<iostream>
#include<math.h>
using namespace std;
float f(float n) {
	if (n < 0) return -n;
	return n;
}
int main() {
	float x0, x1;
	x0= 0;
	x1= cos(x0);
	while (f(x0 - x1) >=pow(10,-6)) {
		x0 = x1;
		x1 = cos(x0);
	}
	cout << "Root = " <<x0;

}