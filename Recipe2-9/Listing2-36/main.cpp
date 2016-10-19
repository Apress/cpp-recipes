#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
private:
    string m_Name;
    int m_Value;

public:
    MyClass(const string& name, int value)
        : m_Name{ name }
        , m_Value{ value }
    {
	cout << "Constructing!" << endl;
    }

    ~MyClass()
    {
        cout << "Destructing!" << endl;
    }

    const string& GetName() const
    {
	return m_Name;
    }

    int GetValue() const
    {
        return m_Value;
    }
};

using MySharedPtr = shared_ptr<MyClass>;
using MyWeakPtr = weak_ptr<MyClass>;

auto PassSharedPtr(MySharedPtr ptr)
{
    cout << "In Function Name: " << ptr->GetName() << endl;
    return ptr;
}

int main()
{
    MyWeakPtr weakPtr;
    {
        auto sharedPointer = make_shared<MyClass>("MyClass", 10);
	weakPtr = sharedPointer;

        {
            auto newSharedPointer = PassSharedPtr(sharedPointer);
            if (sharedPointer)
            {
                cout << "First Object Name: " << sharedPointer->GetName() << endl;
            }

            cout << "Second Object Name: " << newSharedPointer->GetName() << endl;

	    auto sharedFromWeak1 = weakPtr.lock();
	    if (sharedFromWeak1)
	    {
		cout << "Name From Weak1: " << sharedFromWeak1->GetName() << endl;
	    }
	}
    }

    auto sharedFromWeak2 = weakPtr.lock();
    if (!sharedFromWeak2)
    {
	cout << "Shared Pointer Out Of Scope!" << endl;
    }

    return 0;
}
