#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int32_t> stlVector
    {
        1,
        2,
        3,
        4,
        5
    };

    auto iterator = stlVector.begin() + 2;
    stlVector.emplace(iterator, 6);

    for (auto&& number : stlVector)
    {
        std::cout << number << std::endl;
    }

    return 0;
}
