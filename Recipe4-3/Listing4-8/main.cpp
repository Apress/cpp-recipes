#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    bool isTrue{ (10 == 10) && (12 == 12) };
    cout << "True? " << isTrue << endl;

    bool isFalse = isTrue && (1 == 2);
    cout << "True? " << isFalse << endl;

    return 0;
}
