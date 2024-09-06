#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



typedef struct {
    int *q;
    int f;
    int r;
    int size;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* queue);
bool myCircularQueueIsFull(MyCircularQueue* queue);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->f = -1;
    queue->r = -1;
    queue->size = k;

    queue->q = (int*)malloc(sizeof(int) * queue->size);

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* queue, int value) {
    if (myCircularQueueIsFull(queue)) return false;
    if (queue->f == -1) queue->f = 0;
    queue->r = (queue->r + 1) % queue->size;
    queue->q[queue->r] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) return false;
    if (queue->f == queue->r) {
        queue->f = -1;
        queue->r = -1;
    } else {
        queue->f = (queue->f + 1) % queue->size;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* queue) {
    if (!myCircularQueueIsEmpty(queue)) return queue->q[queue->f];
    return -1;
}

int myCircularQueueRear(MyCircularQueue* queue) {
    if (!myCircularQueueIsEmpty(queue)) return queue->q[queue->r];
    return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* queue) {
    return (queue->f == -1);
}

bool myCircularQueueIsFull(MyCircularQueue* queue) {
    return ((queue->f == 0 && queue->r == queue->size - 1) || (queue->f == queue->r + 1));
}

void myCircularQueueFree(MyCircularQueue* queue) {
    free(queue->q);
    free(queue);
}
