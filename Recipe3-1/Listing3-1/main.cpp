#include <iostream>
#include <string>

using namespace std;

namespace
{
    const std::string STRING{ "This is a string"s };
}

int main()
{
    cout << STRING << endl;

    return 0;
}
