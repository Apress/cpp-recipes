#include <iostream>

using namespace std;

class ReferenceCount
{
private:
    int m_Count{ 0 };

public:
    void Increment()
    {
        ++m_Count;
    }

    int Decrement()
    {
        return --m_Count;
    }

    int GetCount() const
    {
        return m_Count;
    }
};

template <typename T>
class SmartPointer
{
private:
    T* m_Object{ nullptr };
    ReferenceCount* m_ReferenceCount{ nullptr };

public:
    SmartPointer()
    {

    }

    SmartPointer(T* object)
        : m_Object{ object }
        , m_ReferenceCount{ new ReferenceCount }
    {
        m_ReferenceCount->Increment();

        cout << "Created smart pointer! Reference count is " << m_ReferenceCount->GetCount() << endl;
    }

    virtual ~SmartPointer()
    {
        if (m_ReferenceCount)
        {
            int decrementedCount = m_ReferenceCount->Decrement();
            cout << "Destroyed smart pointer! Reference count is " << decrementedCount << endl;
            if (decrementedCount <= 0)
            {
                delete m_ReferenceCount;
                delete m_Object;
            }
            m_ReferenceCount = nullptr;
            m_Object = nullptr;
        }
    }

    SmartPointer(const SmartPointer<T>& other)
        : m_Object{ other.m_Object }
        , m_ReferenceCount{ other.m_ReferenceCount }
    {
        m_ReferenceCount->Increment();

        cout << "Copied smart pointer! Reference count is " << m_ReferenceCount->GetCount() << endl;
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other)
    {
        if (this != &other)
        {
            if (m_ReferenceCount && m_ReferenceCount->Decrement() == 0)
            {
                delete m_ReferenceCount;
                delete m_Object;
            }

            m_Object = other.m_Object;
            m_ReferenceCount = other.m_ReferenceCount;
            m_ReferenceCount->Increment();
        }

        cout << "Assigning smart pointer! Reference count is " << m_ReferenceCount->GetCount() << endl;

        return *this;
    }

    SmartPointer(SmartPointer<T>&& other)
        : m_Object{ other.m_Object }
        , m_ReferenceCount{ other.m_ReferenceCount }
    {
        other.m_Object = nullptr;
        other.m_ReferenceCount = nullptr;
    }

    SmartPointer<T>& operator=(SmartPointer<T>&& other)
    {
        if (this != &other)
        {
            m_Object = other.m_Object;
            m_ReferenceCount = other.m_ReferenceCount;

            other.m_Object = nullptr;
            other.m_ReferenceCount = nullptr;
        }
    }

    T& operator*()
    {
        return *m_Object;
    }
};

struct MyStruct
{
public:
    int m_Value{ 0 };

    ~MyStruct()
    {
        cout << "Destroying MyStruct object!" << endl;
    }
};

using SmartMyStructPointer = SmartPointer< MyStruct >;

SmartMyStructPointer PassValue(SmartMyStructPointer smartPointer)
{
    SmartMyStructPointer returnValue;
    returnValue = smartPointer;
    return returnValue;
}

int main(int argc, char* argv[])
{
    SmartMyStructPointer smartPointer{ new MyStruct };
    (*smartPointer).m_Value = 10;

    SmartMyStructPointer secondSmartPointer = PassValue(smartPointer);

    return 0;
}
