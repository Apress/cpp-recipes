#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
private:
    int m_Number{ 0 };

public:
    MyClass(int value)
        : m_Number{ value }
    {

    }

    ~MyClass()
    {
        cout << "Destroying " << m_Number << endl;
    }

    void operator=(const int value)
    {
        m_Number = value;
    }

    int GetNumber() const
    {
        return m_Number;
    }
};

using UniqueMyClass = unique_ptr< MyClass >;

void CreateUniqueObject(UniqueMyClass& referenceToUniquePtr)
{
    UniqueMyClass uniqueMyClass{ make_unique<MyClass>(10) };

    cout << hex << showbase;
    cout << "Address in uniqueMyClass " << uniqueMyClass.get() << endl;

    referenceToUniquePtr.swap(uniqueMyClass);

    cout << "Address in uniqueMyClass " << uniqueMyClass.get() << endl;
}

int main(int argc, char* argv[])
{
    cout << "Begin Main!" << endl;

    UniqueMyClass uniqueMyClass;
    CreateUniqueObject(uniqueMyClass);

    cout << "Address in main's uniqueMyClass " << uniqueMyClass.get() << endl;

    cout << dec << noshowbase << "Back in Main!" << endl;

    return 0;
}
