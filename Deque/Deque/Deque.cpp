#include <iostream>

#define SIZE 5

class Deque {
	int arr[SIZE];
	int FRONT;
	int REAR;

public:
	Deque() {
		FRONT = -1;
		REAR = -1;
		for (int i = 0; i < SIZE; i++) {
			arr[i] = 0;
		}
	}

	bool isEmpty();
	bool isFull();
	void pushFront(int newItem);
	void pushRear(int newItem);
	void popFront();
	void popRear();
	int getFrontElem();
	int getRearElem();

};

bool Deque::isEmpty() {
	if (FRONT == -1) {
		return true;
	}
	return false;
}

bool Deque::isFull() {
	if ((FRONT == 0 && REAR == SIZE - 1) || (FRONT == REAR + 1)) {
		return true;
	}
	return false;
}

void Deque::pushFront(int newItem) {
	if (isFull()) {
		std::cout << "The Deque is Full!";
		return;
	}
	if (FRONT < 1) {
		FRONT = SIZE - 1;
	}
	else {
		FRONT = FRONT - 1;
	}
	arr[FRONT] = newItem;
}

void Deque::pushRear(int newItem) {
	if (isFull()) {
		std::cout << "The Deque is Full!";
		REAR = 0;
		return;
	}
	else if (REAR == SIZE - 1) {
		REAR = 0;
	}
	else {
		REAR = REAR + 1;
	}
	arr[REAR] = newItem;
}

void Deque::popFront() {
	if (isEmpty()) {
		std::cout << "The Deque is empty!";
		return;
	}
	if (FRONT == REAR) {
		FRONT = -1;
		REAR = -1;
	}
	else if (FRONT == SIZE - 1)
	{
		FRONT = 0;
	}
	else {
		FRONT = FRONT + 1;
	}
}

void Deque::popRear() {
    if (isEmpty()) {
        std::cout << "The Deque is empty!";
        return;
    }
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    } 
	else if (REAR == 0) {
		REAR = SIZE - 1;
	}
	else {
        REAR = REAR - 1;
    }
}

int Deque::getFrontElem() {
	if (isEmpty()) {
		std::cout << "The Deque is empty!";
		return -1;
	}
	return arr[FRONT];
}

int Deque::getRearElem() {
	if (isEmpty()) {
		std::cout << "The Deque is empty!";
		return -1;
	}
	return arr[REAR];
}

int main()
{
	Deque dq;

	dq.pushFront(5);
	dq.pushFront(7);
	
	dq.pushRear(4);

	std::cout << dq.getFrontElem() << std::endl;
	std::cout << dq.getRearElem() << std::endl;

	dq.popFront();
	dq.popRear();

	dq.pushFront(3);

	std::cout << dq.getFrontElem() << std::endl;
	std::cout << dq.getRearElem() << std::endl;

}
