#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Admin {
    int id;
    char accountType = 'a';
    string userName;
    string password;
};

struct User {
    int id;
    char accountType = 'u';
    string userName;
    string password;
};

int main()
{
    int choose = 0;
    int accType = 0;
    cout << "What do you want to do?\n1. Log in\n2. Sign in\nEnter your answer: ";
    cin >> choose;
    string login;
    string password;
    switch (choose) {
        case 1:
            cout << ' ';
        case 2:
            cout << "Choose account type:\n1. Admin\n2. User\nEnter your answer: ";
            cin >> accType;
            switch (accType) {
                case 1:
                    cout << "Create login: ";
                    cin >> login;
                    cout << "Create password: ";
                    cin >> password;
                    break;
                case 2:
                    cout << "Create login: ";
                    cin >> login;
                    cout << "Create password: ";
                    cin >> password;
                    break;
                default:
                    cout << "fuck you russia game gta for usa russia gay no gta";
                    break;
            }
            break;
        default:
            cout << "fuck you russia game gta for usa russia gay no gta";
            break;
    }
        
}
