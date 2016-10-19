#include <iostream>

using namespace std;

template <int stringLength>
struct SDBMCalculator
{
    constexpr static unsigned int Calculate(const char* const stringToHash, unsigned int& value)
    {
        unsigned int character{ SDBMCalculator<stringLength - 1>::Calculate(stringToHash, value) };
        value = character + (value << 6) + (value << 16) - value;
        return stringToHash[stringLength - 1];
    }

    constexpr static unsigned int CalculateValue(const char* const stringToHash)
    {
        unsigned int value{};
        unsigned int character{ SDBMCalculator<stringLength>::Calculate(stringToHash, value) };
        value = character + (value << 6) + (value << 16) - value;
        return value;
    }
};

template<>
struct SDBMCalculator < 1 >
{
    constexpr static unsigned int Calculate(const char* const stringToHash, unsigned int& value)
    {
        return stringToHash[0];
    }
};

constexpr unsigned int sdbmHash{ SDBMCalculator<16>::CalculateValue("Bruce Sutherland") };

int main(int argc, char* argv[])
{
    cout << "The hash of Bruce Sutherland is " << sdbmHash << endl;

    return 0;
}
