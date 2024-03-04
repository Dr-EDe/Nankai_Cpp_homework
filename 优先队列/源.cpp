#include<iostream>
#include<list>
using  namespace  std;

template  <typename  T>
class  Queue {
public:
    virtual  int  size() = 0;
    virtual  bool  isEmpty() = 0;
    //入队操作
    virtual  void  enqueue(T  num) = 0;
    //出队操作
    virtual  void  dequeue() = 0;
    //获得队首元素
    virtual  T  front() = 0;
    //获得队尾元素
    virtual  T  back() = 0;
    //若队列中只有一个元素，则既视为队首也视为队尾
};

template  <typename  T>
class  mylist
{
private:
    list<T>  l;
public:
    int  size() {
        return  l.size();
    }
    void  addFirst(T  num) {
        l.push_front(num);
    }
    bool  isEmpty() {
        return  l.empty();
    }
    void  remove(int  index) {
        typename  list<T>::iterator  it = l.begin();
        int  n = index;
        while (n--) {
            it++;
        }
        l.erase(it);
    }
    T  get(int  index) {
        typename  list<T>::iterator  it = l.begin();
        int  n = index;
        while (n--) {
            it++;
        }
        return  *(it);
    }
};
template  <typename  T>
class PriorityQueue:public Queue<T>{
public:
    mylist<T> x;
    int size() {
        return x.size();
    }
    bool isEmpty() {
        return x.isEmpty();
    }
    void enqueue(T num) {
       /* if (x.size() == 0) { x.addFirst(num); return; }
        typename  list<T>::iterator  it = x.l.begin();
        for (int i = 0; i < x.size(); i++) {
            if (num >= x.get(i)) {
                x.l.insert(it, num); return;
            }
            it++;
        }
        x.l.push_back(num); return;*/
        x.addFirst(num);
    }
    T front() {
        T max = -1e9;
        for (int i = 0; i < x.size(); i++) {
            if (max <= x.get(i))max = x.get(i);
        }
        return max;
    }
    void dequeue() {
        for (int i = 0; i < x.size(); i++) {
            if (x.get(i) == front()) {
                x.remove(i); return;
            }
        }
    }
    
    T back() {
        T min = 1e9;
        for (int i = 0; i < x.size(); i++) {
            if (min >= x.get(i)) { min = x.get(i); }
        }
        return min;
    }
};



int  main() {
    int  n, m;
    cin >> n >> m;
    int  ele_int;
    double  ele_dou;
    PriorityQueue<int>  q1;
    PriorityQueue<double>  q2;
    for (int i = 0; i < n; i++) {
        cin >> ele_int;
        q1.enqueue(ele_int);
    }
    for (int i = 0; i < m; i++) {
        cin >> ele_dou;
        q2.enqueue(ele_dou);
    }
    cin >> n >> m >> ele_int >> ele_dou;
    while (n--) {
        if (!q1.isEmpty() && int(q1.front()) > ele_int)  q1.dequeue();
    }
    while (m--) {
        if (!q2.isEmpty() && double(q2.front()) > ele_dou)  q2.dequeue();
    }
    cin >> ele_int >> ele_dou;
    if (q1.isEmpty())q1.enqueue(ele_int);
    if (q2.isEmpty())q2.enqueue(ele_dou);
    cout << q1.size() << "  " << q1.front() << "  " << q1.back() << endl;
    cout << q2.size() << "  " << q2.front() << "  " << q2.back() << endl;
}
