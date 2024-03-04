#include  <iostream>
#include  <algorithm>
#include  <string>
using  namespace  std;

class  Link {
private:
    class  Node {
    public:
        int  data;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    void push_back(int elem) {
      /*  if (tail == head) {
            tail->data = elem;
            head->next = tail;
            return;
        }*/
        Node* cur = new Node();
        cur->data = elem;
        tail->next = cur;
        tail = cur;
        tail->next = NULL;
    }
    void push_front(int elem) {
        Node* cur = new Node();
        cur->data = elem;
        cur->next = head->next;
        head->next = cur;
    }
    int back() {
        return tail->data;
    }
    int front() {
        return head->next->data;
    }
    void insert(int pos, int elem) {
        if(pos==1){
            push_front(elem);
            return;
        }
        Node* cur = new Node();
        cur = head;
        for (int i = 0; i < pos; i++) {
            cur = cur->next;
        }
        Node* arr = head;
        for (int i = 0; i < pos - 1; i++) {
            arr = arr->next;
        }
        Node* temp = new Node();
        temp->data = elem;
        temp->next = cur;
        arr->next = temp;
    }
    void erase(int pos) {
        if (pos == 1) {
            head->next = head->next->next;
            return;
        }
        Node* cur = head;
        for (int i = 0; i < pos - 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    void mysort() {
        Node* cur = head;
        int i = 0;
        while (cur->next != NULL) {
            cur = cur->next; i++;
        }
        for (int j = 0; j < i-1; j++) {
            Node* temp = head->next;
            for (int k = 0; k < i - j - 1; k++) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                }
                temp = temp->next;
            }
        }
    }
    void merge(Link& x) {
        tail->next = x.head->next;
        tail = x.tail;
    }
   int size() {
        Node* cur = head->next;
        int i = 1;
        while (cur->next != NULL) {
            i++;
            cur = cur->next;
        }
        return i;
    }
   int getpos(Node*a) {
       int i = 1;
       Node* b = head->next;
       while (b != a) {
           i++;
           b = b->next;
       }
       return i;
   }
   void myunique() {
       Node* cur = head->next;
       while (cur->next != NULL) {
           Node* temp = cur->next;
           while (temp != NULL) {
               if (temp->data == cur->data) {
                   Node* x = temp->next;
                   erase(getpos(temp));
                   temp = x;
               }
               else temp = temp->next;
           }
           cur = cur->next;
       }
    }
    void clear() {
        head = tail;
    }
    bool empty() {
        return head == tail;
    }
    void show() {
        Node* cur = head->next;
        while (cur != NULL) {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
    Link() {
        tail = new Node();
        head = new Node();
        head = tail;
        tail->next = NULL;
    }
    ~Link() {
        cout << "The destructor is called" << endl;
    }
};
int  main() {
    Link  a, b;
    int  x, y;
    for (int i = 0; i < 5; i++) {
        cin >> x >> y;
        a.push_back(x);
        b.push_front(y);
    }
    a.show();
    b.show();

    cout << a.back() << endl;
    cout << b.front() << endl;;

    a.insert(3, 9);
    a.mysort();
    a.show();

    b.erase(2);
    a.merge(b);
   /* a.myunique();*/
    cout << "The  size  of  a  is  " <<a.size()<< endl;
    a.clear();
    if (a.empty()) {
        cout << "List  is  empty!" << endl;
    }

    return  0;
}

