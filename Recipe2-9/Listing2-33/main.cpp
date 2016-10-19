#include <iostream>
#include <memory>

using namespace std;

#if __cplusplus > 200400L && __cplusplus < 201200L

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args... args)
{
    return unique_ptr<T>{ new T(args...) };
}

#endif

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

int main()
{
    unique_ptr<MyClass> uniquePointer{
	make_unique<MyClass>("MyClass", 10) };

    cout << uniquePointer->GetName() << endl;
    cout << uniquePointer->GetValue() << endl;

    return 0;
}
