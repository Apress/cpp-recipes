#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyClass
{
private:
    int m_Value;

public:
    MyClass(const int value)
        : m_Value{ value }
    {

    }

    int GetValue() const
    {
        return m_Value;
    }

    bool operator <(const MyClass& other) const
    {
        return m_Value < other.m_Value;
    }
};

bool CompareMyClasses(const MyClass& left, const MyClass& right)
{
    return left.GetValue() < right.GetValue();
}

int main(int argc, char* argv[])
{
    vector<int> myIntVector{ 4, 10, 6, 9, 1 };
    auto intMinimum = max_element(myIntVector.begin(), myIntVector.end());
    if (intMinimum != myIntVector.end())
    {
        cout << "Maximum value: " << *intMinimum << std::endl << std::endl;
    }

    vector<MyClass> myMyClassVector{ 4, 10, 6, 9, 1 };
    auto overrideOperatorMinimum = max_element(myMyClassVector.begin(),
        myMyClassVector.end());
    if (overrideOperatorMinimum != myMyClassVector.end())
    {
        cout << "Maximum value: " << (*overrideOperatorMinimum).GetValue() <<
            std::endl << std::endl;
    }

    auto functionComparisonMinimum = max_element(myMyClassVector.begin(),
        myMyClassVector.end(),
        CompareMyClasses);
    if (functionComparisonMinimum != myMyClassVector.end())
    {
        cout << "Maximum value: " << (*functionComparisonMinimum).GetValue() <<
            std::endl << std::endl;
    }

    return 0;
}
