#include<iostream>
using namespace std;
float two(float num1, float num2, int  a) {
	switch (a) {
	case 1:
		return num1 + num2; break;
	case 2:
		return  num1 - num2; break;
	case 3:
		return num1 * num2; break;
	case 4:
		if (num2 == 0)return-99999;
		return  num1 / num2;
	}
}
float four1(float* num, int a, int b, int c) {
	float r1 = two(num[0], num[1], a);
	float r2 = two(r1, num[2], b);
	float r3 = two(r2, num[3], c);
	return r3;
}
float four2(float* num, int a, int b, int c) {
	float r1 = two(num[1], num[2], b);
	float r2 = two(num[0], r1, a);
	float r3 = two(r2, num[3], c);
	return r3;
}
float four3(float* num, int a, int b, int c) {
	float r1 = two(num[0], num[1], a);
	float r2 = two(num[2], num[3], c);
	float r3 = two(r1, r2, b);
	return r3;
}
float four4(float* num, int a, int b, int c) {
	float r1 = two(num[2], num[3], c);
	float r2 = two(num[1], r1, b);
	float r3 = two(num[0], r2, a);
	return r3;
}
float four5(float* num, int a, int b, int c) {
	float r1 = two(num[1], num[2], b);
	float r2 = two(r1, num[3], c);
	float r3 = two(num[0], r2, a);
	return r3;
}
int main() {
	float num[4];
	for (int i = 0; i < 4; i++) {
		cin >> num[i];
	}
	int t = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				if (four1(num, i, j, k) == 24 || four2(num, i, j, k) == 24 || four3(num, i, j, k) == 24 || four4(num, i, j, k) == 24 || four5(num, i, j, k) == 24) {
					t = 1; cout << "yes"; return 0;
				}
			}
		}
	}
	if (t == 0)cout << "no";

}
