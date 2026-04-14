#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

int main()
{
    string email;
    do
    {
        try
        {
            cout << "Enter an email address: ";
            cin >> email;
            if (check_email(email))
            {
                cout << "Valid email address." << endl;
            }
            break;
        }
        catch (const std::invalid_argument &e)
        {
            cout << e.what() << endl;
        }

    } while (true);

    return 0;
}