//#include<iostream>
//using namespace std;
//
//int C(int n, int m) {
//	if (m == 0) { return 1; }
//	int x=1; int y=1;
//	for (int i = 1; i <= m; i++) {
//		x *= i;
//	}
//	for (int i = n; i > n - m; i++) {
//		y *= i;
//	}
//	return y / x;
//}
//void yanghui(int x) {
//	for (int i = 0; i < x; i++) {
//		for (int j = 0; j <= i; j++) {
//			C(i, j);
//		}
//	}
//}