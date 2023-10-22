#include <iostream>
#include <vector>

using namespace std;

class Stack { 
private:
	int top
};

vector<int> createArray() {
	vector<int> array;
	return array;
}
	
void pushInStack(vector<int>& stack, int* TOP, int value) {
	stack.push_back(value);
	++* TOP;
}

void popFromStack(vector<int>& stack, int* TOP) {
	if (*TOP >= 0) {
		stack.pop_back();
		--* TOP;
	} else cout << "\nThe Stack is empty!\n\n";
}

int getPeekElement(vector<int>& stack, int* TOP) {
	if (*TOP >= 0) {
		int peekElem = stack[*TOP];
		cout << "\nYour peek element is: " << peekElem << endl;
		return peekElem;
	} else cout << "\nThe Stack is empty!\n\n";
}

void printStack(vector<int>& stack, int* TOP) {
	if (*TOP >= 0) {
		cout << "\nYour stack is:\n";
		for (int i = 0; i < *TOP + 1; i++) {
			cout << "[" << stack[i] << "]";
		}
		cout << endl;
	} else cout << "\nThe Stack is empty!\n\n";
}


int main() {
	int topNum = -1;
	int* TOP = &topNum;
	
	vector<int> array = createArray(TOP);

	printStack(array, TOP);

	pushInStack(array, TOP, 5);
	pushInStack(array, TOP, 11);
	popFromStack(array, TOP);
	pushInStack(array, TOP, 6);
	printStack(array, TOP);
	getPeekElement(array, TOP);

	pushInStack(array, TOP, 3);
	pushInStack(array, TOP, 52);
	pushInStack(array, TOP, 21);

	printStack(array, TOP);

	getPeekElement(array, TOP);

	popFromStack(array, TOP);
	popFromStack(array, TOP);

	printStack(array, TOP);

	return 0;
}