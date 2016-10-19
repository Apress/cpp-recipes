#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int32_t greaterThan1{ 10 };
    int32_t greaterThan2{ 1 };
    bool isGreaterThan = greaterThan1 > greaterThan2;
    cout << "Is the left greater than the right? " << isGreaterThan << endl;

    int32_t notGreaterThan1{ 10 };
    int32_t notGreaterThan2{ 100 };
    bool isNotGreaterThan = notGreaterThan1 > notGreaterThan2;
    cout << "Is the left greater than the right? " << isNotGreaterThan << endl;

    return 0;
}
