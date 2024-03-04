#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	int min;
	ListNode*next;
	int length;
	void Link(int val,int min,ListNode*next) {
		this->val = val;
		this->min = min;
		this->next = next;
    }
	ListNode() {
		length = 0;
	}
};
class Stack {
	ListNode* head =new ListNode();
public:
	void push(int x) {
		if (head->length==0) {
			head->Link(x, x, NULL); head->length++;
		}
		else {
			ListNode*cur=new ListNode();
			cur->val = head->val;
			cur->min = head->min;
			cur->next = head->next;
			cur->length = head->length;
			head->Link(x, x < head->min ? x : head->min, cur); head->length++;
		}
	}
	void pop() {
		head = head->next; head->length--;
	}
	int  getTop() {
		return head->val;
	}
	int getMin() {
		return head->min;
	}
};
int main() {

	int x;

	cin >> x;

	Stack* obj = new Stack();

	obj->push(x);

	cin >> x;

	obj->push(x);

	cin >> x;

	obj->push(x);

	cout << "getMin():" << obj->getMin() << endl;

	obj->pop();

	cout << "getTop():" << obj->getTop() << endl;

	cout << "getMin():" << obj->getMin() << endl;
	return 0;
}
