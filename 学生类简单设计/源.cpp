#include<iostream>
#include<string.h>
using namespace std;

int x;
class Student {
private:
	struct student{
		int ID;
		char Name[10];
		int Math_score;
		int English_score;
		int Computer_score;
	};
	student* stu = new student[x];
public:
	float sum(student&m) {
		return m.Math_score + m.English_score + m.Computer_score;
	}
	float average(student&m) {
		return sum(m) / 3;
	}
	void display(student&m) {
		cout << "ID:" <<' '<<m.ID << endl;
		cout << "Name:" <<' '<< m.Name << endl;
		cout << "Math score:" <<' '<<m.Math_score << endl;
		cout << "English score:" <<' '<< m.English_score << endl;
		cout << "Computer score:" <<' '<<m.Computer_score << endl;
		cout << "Average score:" <<' '<< average(m) << endl;
		cout << "Total score:" <<' '<< sum(m) << endl;
	}
	void setData() {
		for (int i = 0; i < x; i++) {
			cin >> stu[i].ID;
			cin >> stu[i].Name;
			cin >> stu[i].Math_score;
			cin >> stu[i].English_score;
			cin >> stu[i].Computer_score;
		}
	}
	int findmax() {
		int max = 0;
		for (int i = 1; i < x; i++) {
			if (sum(stu[i]) > sum(stu[max])) {
				max = i;
			}
		}
		return max;
	}
	void displaymax() {
		display(stu[findmax()]);
	}
};
int main() {
	cin >> x;
	Student Stu = Student();
	Stu.setData();
	Stu.displaymax();
	return 0;
}