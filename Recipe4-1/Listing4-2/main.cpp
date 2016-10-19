#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int wholeNumber1{ 64 };
    cout << "wholeNumber1 equals " << wholeNumber1 << endl;

    int wholeNumber2{ wholeNumber1 + 32 };
    cout << "wholeNumber2 equals " << wholeNumber2 << endl;

    int wholeNumber3{ wholeNumber2 - wholeNumber1 };
    cout << "wholeNumber3 equals " << wholeNumber3 << endl;

    int wholeNumber4{ wholeNumber2 * wholeNumber1 };
    cout << "wholeNumber4 equals " << wholeNumber4 << endl;

    int wholeNumber5{ wholeNumber4 / wholeNumber1 };
    cout << "wholeNumber5 equals " << wholeNumber5 << endl;

    int wholeNumber6{ wholeNumber4 % wholeNumber1 };
    cout << "wholeNumber6 equals " << wholeNumber6 << endl;

    return 0;
}
