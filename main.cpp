#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"
using namespace std;

int get_choice(int status = 0)
{
    while (true)
    {
        cout << "1: Sign up" << endl;
        cout << "2: Login" << endl;
        cout << "3: Logout" << endl;
        int choice;
        if (status == 0)
        {
            cout << "Please enter your choice: Sign up, Login";
            cin >> choice;
            switch (choice)
            {
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }
        }
        else if (status == 1)
        {
            cout << "Please enter your choice: Logout";
            cin >> choice;
            switch (choice)
            {
            case 3:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }
        }
        return choice;
    }
}

string verify_email(string email)
{
    while (true)
    {
        cout << "Please enter your email: ";
        cin >> email;
        try
        {
            if (check_email(email))
            {
                return email;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            continue;
        }
    }
}

int main()
{
    map<string, string> user_data;
    string email;
    string password;
    int current_state = 0;
    while (true)
    {
        int choice = get_choice(current_state);
        switch (choice)
        {
        case 1:
            email = verify_email(email);
            cout << "Please enter your password: ";
            cin >> password;
            user_data[email] = password;
            cout << "Sign up successful!" << endl;
            current_state = 1;
            break;

        case 2:
            email = verify_email(email);
            cout << "Please enter your password: ";
            cin >> password;
            if (user_data.find(email) != user_data.end() && user_data[email] == password)
            {
                cout << "Login successful!" << endl;
                current_state = 1;
            }
            else
            {
                cout << "Invalid email or password. Please try again." << endl;
            }
            break;

        case 3:
            cout << "Logout successful!" << endl;
            current_state = 0;
            break;
        }
    }
}
