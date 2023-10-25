#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct queue {
    vector<int> queue;
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

int getPeek(queue* q) {
    if (isQueueEmpty(q)) return 0;
    int peekElem = q->queue[q->FRONT];
    return peekElem;
}

void enqueue(queue* q, int newItem) {
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
    for (int i = q->FRONT; i <= q->REAR; i++) {
        cout << "[" << q->queue[i] << "]";
    }
}

int main()
{
    queue* q = (queue*)malloc(sizeof(queue));

    createQueue(q);

    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 12);

    dequeue(q);

    getPeek(q);


    printQueue(q);

    return 0;

}