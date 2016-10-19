#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    uint32_t bits{ 0x00011000 };
    cout << showbase << hex;
    cout << "Result of 0x00011000 & 0x00011000: " << (bits & bits) << endl;
    cout << "Result of 0x00011000 & 0x11100111: " << (bits & ~bits) << endl;

    return 0;
}
