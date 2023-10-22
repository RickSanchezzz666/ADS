#include <iostream>
#include <vector>

using namespace std;

vector<int> createArray() {
	vector<int> array;
	return array;
}

bool isStackEmpty(vector<int>& stack, int* TOP) {
	if (*TOP == -1 && stack.empty()) {
		cout << "\nThe Stack is empty!\n\n";
		return true;
	}
	else {
		// cout << "\nThe Stack is not empty!\nIt has " << '"' << stack.size() << '"' << " elements.\n";
		return false;
	}
}

void pushInStack(vector<int>& stack, int* TOP, int value) {
	stack.push_back(value);
	++* TOP;
}

void popFromStack(vector<int>& stack, int* TOP) {
	stack.pop_back();
	--* TOP;
}

int getPeekElement(vector<int>& stack, int* TOP) {
	if (isStackEmpty(stack, TOP)) return 0;
	int peekElem = stack[*TOP];
	cout << "\nYour peek element is: " << peekElem << endl;
	return peekElem;
}

void printStack(vector<int>& stack, int* TOP) {
	if (isStackEmpty(stack, TOP)) return;
	cout << "\nYour stack is:\n";
	for (int i = 0; i < *TOP + 1; i++) {
		cout << "[" << stack[i] << "]";
	}
	cout << endl;
}


int main() {
	int topNum = -1;
	int* TOP = &topNum;
	
	vector<int> array = createArray();

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