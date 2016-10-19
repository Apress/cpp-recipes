#include <iostream>
#include <typeinfo>

using namespace std;

class MyClass
{
};

int main()
{
    auto variable{ 1 };
    cout << "Type of variable: " << typeid(variable).name() << endl;

    auto variable2{ MyClass{} };
    cout << "Type of variable: " << typeid(variable2).name() << endl;

    return 0;
}
