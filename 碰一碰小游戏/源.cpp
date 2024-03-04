//#include<iostream>
//using namespace std;
//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void update_position(int* ballposition, int* v, int n) {
//	for (int i = 0; i < n; i++) {
//		ballposition[i] += v[i];
//	}
//}
//void crash(int* ballposition, int* v, int n, int L) {
//	for (int i = 0; i < n; i++) {
//		if (ballposition[i] == 0 || ballposition[i] == L) {
//			v[i] *= -1;
//			continue;
//		}
//		else {
//			for (int j = i + 1; j < n; j++) {
//				if (ballposition[j] == ballposition[i]) {
//					swap(v[j], v[i]);
//				}
//			}
//		}
//	}
//}
//int main() {
//	int n, L, t;
//	cin >> n >> L >> t;
//	int* balls = new int[n];
//	int* v = new int[n];
//	for (int i = 0; i < n; i++) {
//		cin >> balls[i];
//		v[i] = 1;
//	}
//	for (int i = 0; i < t; i++) {
//		update_position(balls, v, n);
//		crash(balls, v, n, L);
//	}
//	for (int i = 0; i < n; i++) {
//		cout << balls[i] << ' ';
//	}

#include<iostream>
using namespace std;

void ball(int* balls, int* v, int L, int t) {
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < sizeof(balls); j++) {
			balls[j] = balls[j] + v[j];
		}
		for (int j = 0; j < sizeof(balls); j++) {
			if (balls[j] == L) { v[j] = -v[j]; }
		}
		for (int j = 0; j < sizeof(balls) - 1; j++) {
			if (balls[j] == balls[j + 1]) { v[j] = -v[j]; v[j + 1] = -v[j + 1]; }
		}
	}
}



void  main() {
	int n, L, t;
	cin >> n >> L >> t;
	int* balls = new int[n];
	int* v = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> balls[i];
		v[i] = 1;
	}
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < i; j++) {
			if (balls[j] > balls[j + 1]) swap(balls[j], balls[j + 1]);
		}
	}
	ball(balls, v, L, t);
	for (int i = 0; i < n; i++) {
		cout << balls[i] << ' ';
	}
}