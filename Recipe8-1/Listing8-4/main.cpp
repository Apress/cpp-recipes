#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main(int arcg, char* argv[])
{
    using IntVector = vector<int32_t>;

    using IntVectorIterator = IntVector::iterator;
    using ConstIntVectorIterator = IntVector::const_iterator;

    using ReverseIntVectorIterator = IntVector::reverse_iterator;
    using ConstReverseIntVectorIterator = IntVector::const_reverse_iterator;

    IntVector myVector(5, 0);
    int32_t value { 0 };
    for (ReverseIntVectorIterator iter = myVector.rbegin(); iter != myVector.rend(); ++iter)
    {
        *iter = value++;
    }

    for (ConstIntVectorIterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter)
    {
        cout << "The value is: " << *iter << endl;
    }

    return 0;
}
