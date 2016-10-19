#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int32_t equal1{ 10 };
    int32_t equal2{ 10 };
    bool isEqual = equal1 == equal2;
    cout << "Are the numbers equal? " << isEqual << endl;

    int32_t notEqual1{ 10 };
    int32_t notEqual2{ 100 };
    bool isNotEqual = notEqual1 == notEqual2;
    cout << "Are the numbers equal? " << isNotEqual << endl;

    return 0;
}
