#include  <iostream>
using  namespace  std;

typedef  struct  Link
{
    int  data;
    struct  Link* next;
}  Link;

typedef  struct  Queue
{
    Link* front;
    Link* rear;
}  Queue;

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front  = q->rear=(Link*)malloc(sizeof(Link));
    q->front->next = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    if (q->front == q->rear) {
        return true;
    }
    else return false;
}

void clearQueue(Queue* q) {
    q->rear = q->front;
    q->front->next = NULL;
}

int getLen(Queue* q) {
    int i = 0;
    Link* temp = q->front;
    while (temp !=q->rear) {
        i++;
        temp = temp->next;
    }
    return i;
}

void printQueue(Queue* q) {
    Link* temp = q->front;
    while (temp!=q->rear) {
        temp = temp->next;
        cout << temp->data << ' ';
    }
    cout << endl;
}

void enQueue(Queue* q, int data) {
    Link* newnode = (Link*)malloc(sizeof(Link));
    newnode->data = data;
    newnode->next = NULL;
    q->rear->next = newnode;
    q->rear = newnode;
}

void deQueue(Queue* q) {
    if (q->front != q->rear) {
        q->front = q->front->next;
    }
}

int getFront(Queue* q) {
    Link* temp = q->front->next;
    return temp->data;
}

int getElem(Queue* q, int i) {
    Link* temp = q->front;
    for (int j = 0; j < i; j++) {
        temp = temp->next;
    }
    return temp->data;
}


void updateElem(Queue* q, int i, int data) {
    Link* temp = q->front;
    for (int j = 0; j < i;j++) {
        temp = temp->next;
    }
    temp->data = data;
}



int  main() {
    Queue* q = initQueue();
    cout << isEmpty(q) << endl;
    cout << getLen(q) << endl;
    printQueue(q);
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    enQueue(q, 6);
    cout << isEmpty(q) << endl;
    cout << getLen(q) << endl;
    cout << getFront(q) << endl;
    printQueue(q);
    deQueue(q);
    deQueue(q);
    cout << getLen(q) << endl;
    printQueue(q);
    cout << getFront(q) << endl;
    cout << getElem(q, 2) << endl;
    cout << getElem(q, 4) << endl;
    updateElem(q, 3, 10);
    printQueue(q);
}