#include <stdlib.h>
#include <iostream>
#include <vector>

#define SIZE 10

using namespace std;

struct queue {
    int queue[SIZE];
    int FRONT;
    int REAR;
};

void createQueue(queue* q) {
    q->FRONT = -1;
    q->REAR = -1;
}

bool isQueueEmpty(queue* q) {
    if (q->FRONT == -1 && q->REAR == -1) {
        cout << "\nThe queue is empty!\n";
        return true;
    } else return false;
}

bool isQueueFull(queue* q) {
    if (q->REAR == SIZE - 1) {
        cout << "\nThe queue is full!\n";
        return true;
    } else return false;
}

int getPeek(queue* q) {
    if (isQueueEmpty(q)) return 0;
    int peekElem = q->queue[q->FRONT];
    cout << "\nPeek element: " << peekElem << endl;
    return peekElem;
}

void enqueue(queue* q, int newItem) {
    if (isQueueFull(q)) return;
    q->FRONT = 0;
    ++q->REAR;
    q->queue[q->REAR] = newItem;
}

int dequeue(queue* q) {
    if (isQueueEmpty(q)) return 0;
    ++q->FRONT;
    if (q->FRONT >= q->REAR) {
        createQueue(q);
    }
    return q->FRONT;
}

void printQueue(queue* q) {
    if (isQueueEmpty(q)) return;
    cout << "\nFront element: " << q->FRONT << "\nRear Element: " << q->REAR << "\nThe queue: ";
    for (int i = q->FRONT; i <= q->REAR; i++) {
        cout << "[" << q->queue[i] << "]";
    }
    cout << endl;
}

int main()
{
    queue* q = new queue;

    createQueue(q);

    dequeue(q);

    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 12);

    printQueue(q);
    getPeek(q);

    dequeue(q);

    printQueue(q);
    getPeek(q);

    delete q;

    return 0;

}