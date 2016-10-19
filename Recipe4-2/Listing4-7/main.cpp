#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int32_t lessThan1{ 1 };
    int32_t lessThan2{ 10 };
    bool isLessThan = lessThan1 < lessThan2;
    cout << "Is the left less than the right? " << isLessThan << endl;

    int32_t notLessThan1{ 100 };
    int32_t notLessThan2{ 10 };
    bool isNotLessThan = notLessThan1 < notLessThan2;
    cout << "Is the left less than the right? " << isNotLessThan << endl;

    return 0;
}
