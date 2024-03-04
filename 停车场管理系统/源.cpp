#include<iostream>
using namespace std;
#include<vector>
#include<queue>
int N;
class Time {
public:
	int year; int month; int day; int hour; int minute; int second;
	void operator = (Time time1);
	int operator-(Time time1);
	Time operator+(int t);
	friend  std::istream& operator>>(std::istream&, Time&f);
	friend  std::ostream& operator<<(std::ostream&,Time const& f);
	Time() {
		year = 0; month = 0; day = 0; hour = 0; minute = 0; second = 0;
	}
};
void Time::operator=(Time time1) {
	year = time1.year; month = time1.month; day = time1.day; hour = time1.hour; minute = time1.minute; second = time1.second;
}
int Time:: operator-(Time time1) {

}
std::istream& operator>>(std::istream&, Time& f) {
	cin >> f.year >> f.month >> f.day >> f.hour >> f.minute >> f.second;
	return cin;
}
std::ostream& operator<<(std::ostream&, Time const& f) {
	cout << f.year << '��' << f.month << '��' << f.day << '��' << f.hour << 'ʱ' << f.minute << '��' << f.second << '��' << endl;
	return cout;
}
Time Time::operator+(int t1) {
	
}
struct carsite {
	string carname;
	Time parktime;
	Time leavetime;
};
struct carinfor {
	string car_name;
	Time cintime;
};
queue<carinfor>carwaiting;//ͣ�������Ŷӵĳ�
class Parkinglot {
private:
	int n;//n����ʣ�೵λ
	vector<carsite>p;
public:
	void show();//��ʾʣ�೵λ
	void park(carinfor);//ͣ��
	void leave(int a);//�뿪���ɷ�
	void fees(int a);//�����a��λ�õĸý��ɵ�ͣ����
	Parkinglot();
};
void Parkinglot::show() {
	cout << "ʣ�೵λ��" << n << "��" << endl;
}
void Parkinglot::park(carinfor a) {
	if (p.size() >= N) { carwaiting.push(a); return; }
	else{
		carsite temp;
		temp.carname = a.car_name;
		temp.parktime = a.cintime;
		p.push_back(temp); return;
	}
}
void Parkinglot::leave(int a){
	cin >> p[a - 1].leavetime;
	fees(a);
	if (a == n) { fees(a); p.pop_back(); }
	else {
		for (int i = a - 1; i < n; i++) {
			p[i].leavetime = p[a - 1].leavetime;
			fees(i); p[i].parktime =p[i].parktime+ 10;
		}
		for (int i = a; i < n; i++) {
			p[i - 1] = p[i];
		}
		p.pop_back();
	}
}
void Parkinglot::fees(int a) {
	if (p[a - 1].leavetime - p[a - 1].parktime <= 1800) { return; }
	else if (p[a - 1].leavetime - p[a - 1].parktime > 1800 && p[a - 1].leavetime - p[a - 1].parktime <= 7200) { cout << "��Ӧ���ɵķ�����3Ԫ" << endl; }
	else if (p[a - 1].leavetime - p[a - 1].parktime > 7200 && p[a - 1].leavetime - p[a - 1].parktime <= 24 * 3600) { cout << "��Ӧ���ɵķ�����10Ԫ" << endl; }
	else { cout << "��Ӧ���ɵķ�����15Ԫ" << endl; }
}
 




int main() {

}