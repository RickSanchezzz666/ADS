#include <iostream>

using namespace std;

template<typename Type>
int createID(Type obj) {
	return ++ID;
	}

int main()
{
	int a = 0;
	createID<int>(a);
	createID(a);
	
}
