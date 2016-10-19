#include <iostream>

using namespace std;

unsigned int counter{ 0 };

void IncreaseCounter()
{
    counter += 10;
    cout << "counter is " << counter << endl;
}

int main(int argc, char* argv[])
{
    counter += 5;
    cout << "counter is " << counter << endl;

    IncreaseCounter();

    return 0;
}
