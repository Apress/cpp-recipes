#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "Constructor called!" << endl;
    }

    ~MyClass()
    {
        cout << "Destructor called!" << endl;
    }
};

int main(int argc, char* argv[])
{
    MyClass myClass;

    cout << "Function body!" << endl;

    return 0;
}
