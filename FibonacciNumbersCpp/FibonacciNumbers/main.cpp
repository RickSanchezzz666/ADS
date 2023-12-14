#include <iostream>
#include <vector>
#include <fstream>

void getFibonacciNumbers(int endIt, std::ostream& output);
void getFibonacciNumbersToFile(int endIt, const std::string& fileName);

int main() {
	getFibonacciNumbers(10, std::cout);
	getFibonacciNumbersToFile(15, "fibonacciNumbers.txt");
	return 0;
}

void getFibonacciNumbers(int endIt, std::ostream& output) {
	std::vector<int> arr = { 0, 1, 1};

	for (int i = 1; i < endIt - 2; i++) {
		arr.push_back(arr[i] + arr[i + 1]);
	}

	for (int x : arr) {
		output << x << " ";
	}
}


void getFibonacciNumbersToFile(int endIt, const std::string& fileName) {
	std::vector<int> arr = { 0, 1, 1 };

	for (int i = 1; i < endIt - 2; i++) {
		arr.push_back(arr[i] + arr[i + 1]);
	}

	std::ofstream outputFile(fileName);

	if (outputFile.is_open()) {
		for (int x : arr) {
			outputFile << x << " ";
		}
		outputFile.close();
		std::cout << "\nSuccesfully writed in the file!\n";
	}
	else {
		std::cerr << "\nUnable to open file for writing!\n";
	}
}