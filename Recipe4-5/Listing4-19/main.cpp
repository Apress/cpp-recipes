#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    const uint32_t maskBits{ 16 };
    int32_t leftShifted{ 0x00008080 << maskBits };
    cout << showbase << hex;
    cout << "Left shifted: " << leftShifted << endl;

    int32_t lowerMask{ 0x0000FFFF };
    leftShifted |= (0x11110110 & lowerMask);
    cout << "Packed left shifted: " << leftShifted << endl;

    int32_t rightShifted{ (leftShifted >> maskBits) };
    cout << "Right shifted: " << rightShifted << endl;
    cout << "Unmasked right shifted: " << (rightShifted & lowerMask) << endl;

    return 0;
}
