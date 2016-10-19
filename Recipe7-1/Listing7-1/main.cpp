#include <cinttypes>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    const uint32_t numberOfElements{ 5 };
    int32_t normalArray[numberOfElements]{ 10, 65, 3000, 2, 49 };

    for (uint32_t i{ 0 }; i < numberOfElements; ++i)
    {
        cout << normalArray[i] << endl;
    }   

    return 0;
}
