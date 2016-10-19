#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main()
{
    auto currentTimePoint = system_clock::now();
    auto currentTime = system_clock::to_time_t( currentTimePoint );
    auto timeText = ctime( &currentTime );

    cout << timeText << endl;

    return 0;
}
