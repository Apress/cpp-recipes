#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main(int arcg, char* argv[])
{
    using IntVector = vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;

    IntVector myVector(5, 0);
    int32_t value{ 0 };
    for (IntVectorIterator iter = myVector.begin(); iter != myVector.end(); ++iter)
    {
        *iter = value++;
    }

    for (IntVectorIterator iter = myVector.begin(); iter != myVector.end(); ++iter)
    {
        cout << "The value is: " << *iter << endl;
    }

    return 0;
}
