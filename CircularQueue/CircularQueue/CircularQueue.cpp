#include <iostream>

#define SIZE 5

struct CircularQueue {
	int elements[SIZE];
	int FRONT;
	int REAR;
};
typedef struct CircularQueue queue;

void createQueue(queue* q) {
	q->FRONT = -1;
	q->REAR = -1;
}

bool isFull(queue* q) {
	if ((q->FRONT == 0 && q->REAR == SIZE - 1) || (q->FRONT == q->REAR + 1)) {
		std::cout << "\nThe Queue is Full!";
		return true;
	}
	return false;
}

bool isEmpty(queue* q) {
	if (q->FRONT == -1) {
		std::cout << "\nThe Queue is Empty!";
		return true;
	}
	return false;
}

int getPeek(queue* q) {
	if (isEmpty(q)) return 0;
	int peekElem = q->elements[q->FRONT];
	std::cout << "\nYour peek element is: " << peekElem;
	return peekElem;
}

void enqueue(queue* q, int newItem) {
	if (isFull(q)) return;
	if (q->FRONT == -1) {
		q->FRONT = 0;
	};
	q->REAR = (q->REAR + 1) % SIZE;
	q->elements[q->REAR] = newItem;
}

int dequeue(queue* q) {
	if (isEmpty(q)) return 0;
	if (q->FRONT == q->REAR) {
		createQueue(q);
	}
	else {
		q->FRONT = (q->FRONT + 1) % SIZE;
	}
	return q->FRONT;
}

void display(queue* q) {
	if (isEmpty(q)) return;
	std::cout << "\nYour Circular Queue: ";
	if (q->REAR >= q->FRONT) {
		for (int i = q->FRONT; i <= q->REAR; i++) {
			std::cout << "[" << q->elements[i] << "]";
		}
	}
	else {
		for (int i = q->FRONT; i < SIZE; ++i) {
			std::cout << "[" << q->elements[i] << "]";
		}	
		for (int i = 0; i <= q->REAR; i++) {
			std::cout << "[" << q->elements[i] << "]";
		}
		
	}
}


int main() {
	queue* q = new queue;

	createQueue(q);

	enqueue(q, 5);
	enqueue(q, 14);
	enqueue(q, 3);
	enqueue(q, 6);
	enqueue(q, 2);

	display(q);
	getPeek(q);

	dequeue(q);
	dequeue(q);

	enqueue(q, 13);
	enqueue(q, 56);

	display(q);
	getPeek(q);

	dequeue(q);

	display(q);
	getPeek(q);

	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);

	display(q);
}