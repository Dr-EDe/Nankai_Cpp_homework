#include<iostream>
using namespace std;


int main() {
	int m; cin >> m;
	struct student {
		int num;
		double score;
	};
	student* stu = new student[m];
	for (int i = 0; i < m; i++) {
		cin >> stu[i].num;
	}
	for (int i = 0; i < m; i++) {
		cin >> stu[i].score;
	}
	double all = 0;
	for (int i = 0; i < m; i++) {
		all += stu[i].score;
	}
	double max = stu[0].score; int n = stu[0].num;
	for (int i = 1; i < m; i++) {
		if (stu[i].score >=max) {
			max = stu[i].score;
			n = stu[i].num;
		}
	}
	cout << all / m << ' ' << n << ' ' << max;
	system("pause");

	return 0;

}