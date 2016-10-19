#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    bool isTrue{ (1 == 1) || (0 == 1) };
    cout << "True? " << isTrue << endl;

    isTrue = (0 == 1) || (1 == 1);
    cout << "True? " << isTrue << endl;

    isTrue = (1 == 1) || (1 == 1);
    cout << "True? " << isTrue << endl;

    isTrue = (0 == 1) || (1 == 0);
    cout << "True? " << isTrue << endl;

    return 0;
}
