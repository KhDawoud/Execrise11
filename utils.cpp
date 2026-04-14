#include <string>
#include <regex>
#include <stdexcept>
using namespace std;

bool check_email(string email)
{
    regex pattern(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.com$)");
    if (regex_match(email, pattern))
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Invalid email format");
    }
}