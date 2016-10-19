#include <iostream>

using namespace std;

class MyClass
{
private:
    static int m_Count;
    int m_Instance{ -1 };

public:
    MyClass()
        : m_Instance{m_Count++}
    {
        cout << "Constructor called on " << m_Instance << endl;
    }

    ~MyClass()
    {
        cout << "Destructor called on " << m_Instance << endl;
    }
};

int MyClass::m_Count{ 0 };

int main(int argc, char* argv[])
{
    MyClass myClass1;

    {
        MyClass myClass2;

        {
            MyClass myClass3;
        }
    }

    return 0;
}
