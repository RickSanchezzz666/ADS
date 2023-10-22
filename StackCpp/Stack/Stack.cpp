#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
	vector<int> stack;
	int TOP;
public:
	Stack() : TOP(-1) {}

	void pushInStack(int value) {
		stack.push_back(value);
		++ TOP;
	}

	void popFromStack() {
		if (TOP >= 0) {
			stack.pop_back();
			-- TOP;
		}
		else {
			cout << "\nThe Stack is empty!\n\n";
			return;
		}
	}

	int getPeekElement() {
		if (TOP >= 0) {
			int peekElem = stack[TOP];
			cout << "\nYour peek element is: " << peekElem << endl;
			return peekElem;
		}
		else {
			cout << "\nThe Stack is empty!\n\n";
			return 0;
		}
	}

	void printStack() {
		if (TOP >= 0) {
			cout << "\nYour stack is:\n";
			for (int i = 0; i < TOP + 1; i++) {
				cout << "[" << stack[i] << "]";
			}
			cout << endl;
		}
		else {
			cout << "\nThe Stack is empty!\n\n";
			return;
		}
	}
};



int main() {
	Stack stack;

	stack.printStack();

	stack.pushInStack(5);
	stack.pushInStack(11);
	stack.popFromStack();
	stack.pushInStack(6);
	stack.printStack();
	stack.getPeekElement();

	stack.pushInStack(3);
	stack.pushInStack(52);
	stack.pushInStack(21);

	stack.printStack();

	stack.getPeekElement();

	stack.popFromStack();
	stack.popFromStack();

	stack.printStack();

	return 0;
}