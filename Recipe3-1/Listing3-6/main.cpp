#include <iostream>
#include <string>

using namespace std;

#define DEBUG_STRING_LITERALS !NDEBUG

namespace
{
#if DEBUG_STRING_LITERALS
    using DebugStringLiteral = string;
#endif

#if DEBUG_STRING_LITERALS
    DebugStringLiteral STRING{ "This is a String!"s };
#endif
}

int main()
{
#if DEBUG_STRING_LITERALS
    cout << STRING << endl;
#endif

    return 0;
}
