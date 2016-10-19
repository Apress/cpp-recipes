#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string myString{ "Bruce Sutherland" };

    auto found = find(myString.begin(), myString.end(), 'e');
    while (found != myString.end())
    {
        cout << "Found: " << *found << endl;

        found = find(found+1, myString.end(), 'e');
    }

    return 0;
}
