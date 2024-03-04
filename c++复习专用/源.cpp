#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<cstring>
using namespace std;

//int*func_sort_ascend(int* p, int n, float& mid) {
//	for (int i = 0; i < n; i++) {
//		for (int j =0; j < n-i-1; j++) {
//			if (p[j] > p[j + 1]) {
//				swap(p[j], p[j + 1]);
//			}
//		}
//	}
//	if (n % 2 == 0) {
//		mid = (p[n / 2] + p[(n / 2) - 1]) / 2;
//	}
//	else mid = p[(n - 1) / 2];
//	return p;
//}
//int main() {
//	int p[6] = { 1,4,2,6,4,9 };
//	float mid;
//	func_sort_ascend(p, 6, mid);
//	cout << mid;
//	for (int i = 0; i < 6; i++) {
//		cout << p[i];
//	}
//}




//struct Linklist {
//	int num;
//	Linklist* node;
//};
//Linklist* initLink() {
//	Linklist* head = new Linklist();
//	head->node = NULL;
//	return head;
//}
//bool isEmpty(Linklist* head) {
//	return head->node == NULL;
//}
//int getlen(Linklist* head) {
//	int n = 0;
//	Linklist* temp = head;
//	while (temp->node != NULL) {
//		n++;
//		temp = temp->node;
//	}
//	return n;
//}
//void printLinklist(Linklist* head) {
//	Linklist* temp = head->node;
//	while (temp != NULL) {
//		cout << temp->num << ' ';
//		temp = temp->node;
//	}
//}
//void addNode(Linklist* head, int elem) {
//	Linklist* temp = head;
//	while (temp->node != NULL) {
//		temp = temp->node;
//	}
//	Linklist* x = new Linklist();
//	x->num = elem;
//	x->node = NULL;
//	temp->node= x;
//}
//void insert(Linklist* head, int i, int elem) {
//	Linklist* temp = head->node;
//	Linklist* cur;
//	for (int j = 0; j < i-1; j++) {
//		temp = temp->node;
//	}
//	cur = temp->node;
//	Linklist* x = new Linklist();
//	x->num = elem;
//	x->node = cur;
//	temp->node = cur;
//}
//void delNode(Linklist* head, int i) {
//	Linklist* temp = head;
//	for (int j = 0; j < i-1; j++) {
//		temp = temp->node;
//	}
//	temp->node = temp->node->node;
//}
//void updateNode(Linklist* head, int i, int elem) {
//	Linklist* temp = head;
//	for (int j = 0; j < i-1; j++) {
//		temp = temp->node;
//	}
//	temp->num = elem;
//}
//int main() {
//	Linklist* head = initLink();
//	cout << isEmpty(head) << endl;
//	addNode(head, 1);
//	cout << isEmpty(head) << endl;
//	addNode(head, 2);
//	addNode(head, 4);
//	addNode(head, 3);
//	addNode(head, 9);
//	printLinklist(head);
//	cout << getlen(head);
//}


//class vector {
//private:
//	float x;
//	float y;
//public:
//	vector(float a, float b) {
//		x = a; y = b;
//	}
//	float mode() {
//		return sqrt(x * x + y * y);
//	}
//	friend vector& operator+(vector&a,vector&b) {
//		vector c = vector(a.x + b.x, c.y = a.y + b.y);
//		return c;
//	}
//	friend float operator*(vector& a, vector& b) {
//		return a.x * b.x + a.y * b.y;
//	}
//	friend vector& operator-(vector& a) {
//		a.x = -a.x;
//		a.y = -a.y;
//		return a;
//	}
//	friend bool operator<(vector& a, vector& b) {
//		return a.mode() < b.mode();
//	}
//	vector& operator=(vector& a) {
//		x = a.x;
//		y = a.y;
//		return *this;
//	}
//	friend ostream& operator<<(ostream& out, vector& a) {
//		out << a.x << a.y<< endl;
//		return out;
//	}
//};
//int main() {
//	float x1, x2, y1, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	vector v1 = vector(x1, y1);
//	vector v2 = vector(x2, y2);
//	vector v3 = v1 + v2;
//	cout << v1 * v2;
//	cout << -v1;
//	if (-v1 < v2) {
//		cout << "yes";
//	}
//	else cout << "no";
//}



//class PalindromeJudge {
//public:
//	virtual bool isPalindrome() = 0;
//};
//
//class StringPalindromeJudge :public PalindromeJudge {
//private:
//	char* ctr;
//public:
//	StringPalindromeJudge( const char* str) {
//		ctr = new char[strlen(str) + 1];
//		strcpy_s(ctr, strlen(str)+1,str);
//	}
//	virtual bool isPalindrome() {
//		int n =strlen(ctr);
//		for (int i = 0; i < n/2; i++) {
//			if (ctr[i] != ctr[n - i - 1]) {
//				return false;
//			}
//		}
//		return true;
//	}
//};
//class IntegerPalindromeJudge :public PalindromeJudge {
//private:
//	int arr;
//public:
//	IntegerPalindromeJudge(int a) {
//		arr = a;
//	}
//	virtual bool isPalindrome() {
//		int a = 0;
//		int b = arr;
//		while (b > 0) {
//			a =a*10+ b % 10;
//			b = b / 10;
//		}
//		return a == arr;
//	}
//};
//int main() {
//	const char* str = "hakudsj";
//	int s;
//	cin  >> s;
//	IntegerPalindromeJudge x = IntegerPalindromeJudge(s);
//	StringPalindromeJudge y = StringPalindromeJudge(str);
//	PalindromeJudge* p;
//	p = &x;
//	cout << p->isPalindrome() << endl;
//	p = &y;
//	cout<<p->isPalindrome();
//}

//const int maxsize = 10;
//class minstack {
//	int stack[maxsize];
//	int top;
//public:
//	void push(int x) {
//		stack[++top] = x;
//	}
//	void pop() {
//		top--;
//	}
//	int stop() {
//		return stack[top];
//	}
//	int getMin() {
//		int min = stack[0];
//		for (int i = 1; i <= top; i++) {
//			if (min > stack[i]) {
//				min = stack[i];
//			}
//		}
//		return min;
//	}
//	minstack() {
//		top = -1;
//	}
//};
//int main() {
//	int x;
//	cin >> x;
//	minstack* obj = new minstack();
//	obj->push(x);
//	cin >> x;
//	obj->push(x);
//	cin >> x;
//	obj->push(x);
//	cout << "getMin():" << obj->getMin() << endl;
//	obj->pop();
//	cout << "top():" <<obj->stop()<< endl;
//	cout << "getMin():" << obj->getMin() << endl;
//	system("pause");
//	return 0;
//}


//class info {
//public:
//	int id;
//	char* username;
//	char* password;
//	info() { id = -1; username = NULL; password = NULL; }
//	info(int ID, char* name, char* p) {
//		id = ID;
//		username = new char[strlen(name) + 1];
//		for (int i = 0; i < strlen(name); i++) {
//			username[i] = name[i];
//		}
//		password = new char[strlen(p) + 1];
//		for (int i = 0; i < strlen(p); i++) {
//			password[i] = p[i];
//		}
//	}
//};
//class Database {
//	
//	int count;
//	int capacity;
//public:
//	info* data;
//	bool push(info f) {
//		if (count = capacity) {
//			return false;
//		}
//		for (int i = 0; i < count; i++) {
//			if (f.id == data[i].id) {
//				return false;
//			}
//		}
//		data[count++] = f;
//		return true;
//	}
//	void get(int m) {
//		for (int i = 0; i < count; i++) {
//			if (data[i].id == m) {
//				cout << "id:" << data[i].id << ' ' << "name" << data[i].username << ' ' << "password" << data[i].password << endl;
//				return;
//			}
//		}
//	}
//	bool delete_(int m) {
//		int i = 0;
//		for ( i = 0; i < count; i++) {
//			if (data[i].id == m) {
//				for (int j = i; j < count - 1; j++) {
//					data[j] = data[j + 1];
//				}
//				count--;
//				return true;
//			}
//		}
//		return false;
//	}
//	Database(int max) {
//		count = 0;
//		capacity = max;
//		data = new info[capacity];
//	}
//};
//
//
//int main() {
//	int  capacity, total_data_number, id, delete_data_number;
//	char  username[10];
//	char  password[10];
//	cin >> capacity >> total_data_number;
//	Database  d(capacity);
//	int* id_array = new  int[total_data_number];
//	for (int p = 0; p < total_data_number; p++) {
//		cin >> id >> username >> password;
//		d.push(info(id, username, password));
//	}
//	cout << d.data[0].id << ' ' << d.data[0].password;
//	/*cin >> delete_data_number;
//	for (int q = 0; q < delete_data_number; q++) {
//		cin >> id;
//		d.delete_(id);
//	}*/
//	d.get(1);
//
//}


//template<typename T>
//void sort(T* arr) {
//	for (int i = 0; i < sizeof(arr) / sizeof(T); i++) {
//		for (int j = 0; j < sizeof(arr) / sizeof(T) - i - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				T temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//template<class T>
//T sum(T* a) {
//	T SUM = 0;
//	for (int i = 0; i < sizeof(a) / sizeof(T); i++) {
//		SUM += a[i];
//	}
//	return SUM;
//}
//
//template<class T,class A>
//bool larger(T* a, A* b) {
//	if (sum<T>(a) > sum<A>(b)) {
//		return true;
//	}
//	return false;
//}
//
//int  main() {
//	int  count;
//	cin >> count;
//	int* data_int = new  int[count];
//	float* data_float = new  float[count];
//	for (int i = 0; i < count; i++)
//		cin >> data_int[i];
//	for (int i = 0; i < count; i++)
//		cin >> data_float[i];
//	sort(data_int);
//	cout << sizeof(data_int);
//	for (int i = 0; i < count; i++)
//		cout << data_int[i] << "  ";
//	cout << endl;
//	sort(data_float);
//	for (int i = 0; i < count; i++)
//		cout << data_float[i] << "  ";
//	cout << endl;
//	cout << larger(data_int, data_float);
//	return  0;
//}



int const male = 1;
int const female = 0;
class School {
public:
	void Append();
};

class Person {
public:
	char* name;
	int sex;
	void virtual Showme();
};

class Staff :public Person {
	int staff_num;
public:
	void virtual Showme() {
		cout << name << ' ' << sex << ' ' << staff_num << endl;
	}
	Staff(char* Name, int s, int num) :Person(Name, s) {

	}
};
class Student :public Person {
	int student_num;
public:
	void virtual Showme() {
		cout << name << ' ' << sex << ' ' << student_num << endl;
	}

};