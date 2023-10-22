#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int* ptr = &i;

    cout << *ptr;
    *ptr = 1;
    cout << i << *ptr;
}
