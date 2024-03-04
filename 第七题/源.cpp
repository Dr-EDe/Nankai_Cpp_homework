#include<iostream>

using namespace std;


int main() {
	struct student {
		int    id;
		char name[10];
		double height;
		double weight;
	};
	int N, M;
	cin >> N >> M;
	student* stu = new student[N];
	for (int i = 0; i < N; i++) {
		cin >> stu[i].id >> stu[i].name >> stu[i].height >> stu[i].weight;
	}
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >i; j--) {
			if (stu[j].height > stu[j - 1].height) {
				student temp = stu[j];
				stu[j] = stu[j - 1];
				stu[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cout << stu[i].id << ' ' << stu[i].name << ' ' << stu[i].height << ' ' << stu[i].weight << endl;
	}
	system("pause");

	return 0;

}