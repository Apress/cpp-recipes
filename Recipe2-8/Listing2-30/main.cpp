#include <iostream>

using namespace std;

class MyClass
{
private:
    static int s_Counter;

    int* m_Member{ &s_Counter };

public:
    MyClass()
    {
	++(*m_Member);
	cout << "Constructing: " << GetValue() << endl;
    }

    ~MyClass()
    {
	if (m_Member)
	{
            --(*m_Member);
	    m_Member = nullptr;
	    
	    cout << "Destructing: " << s_Counter << endl;
	}
        else
	{
	    cout << "Destroying a moved-from instance" << endl;
	}
    }

    MyClass(const MyClass& rhs)
        : m_Member{ rhs.m_Member }
    {
        ++(*m_Member);
        cout << "Copying: " << GetValue() << endl;
    }

    MyClass(MyClass&& rhs)
	: m_Member{ rhs.m_Member }
    {
	cout << hex << showbase;
	cout << "Moving: " << &rhs << " to " << this << endl;
	cout << noshowbase << dec;
	rhs.m_Member = nullptr;
    }

    int GetValue() const
    {
        return *m_Member;
    }
};

int MyClass::s_Counter{ 0 };

MyClass CopyMyClass(MyClass parameter)
{
    return parameter;
}

int main()
{
    auto object1 = MyClass();

    {
	auto object2 = MyClass();
    }

    auto object3 = MyClass();
    auto object4 = CopyMyClass(object3);

    return 0;
}
