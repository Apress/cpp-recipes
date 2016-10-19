#include <ctime>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;
using namespace literals;

int main()
{
    auto startTimePoint = system_clock::now();

    this_thread::sleep_for(5s);

    auto endTimePoint = system_clock::now();

    auto timeTaken = duration_cast<milliseconds>(endTimePoint - startTimePoint);

    cout << "Time Taken: " << timeTaken.count() << endl;

    return 0;
}
