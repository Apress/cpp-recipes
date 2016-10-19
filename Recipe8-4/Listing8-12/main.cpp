#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string myString{ "Bruce Sutherland!" };

    auto numberOfCapitals = count_if(
        myString.begin(),
        myString.end(),
        [](auto&& character)
        {
            return static_cast<bool>(isupper(character));
        });
    cout << "The number of capitals: " << numberOfCapitals << endl;

    auto numberOfLowerCase = count_if(
        myString.begin(),
        myString.end(),
        [](auto&& character)
        {
            return static_cast<bool>(islower(character));
        });
    cout << "The number of lower case letters: " << numberOfLowerCase << endl;

    auto numberOfAlphaNumerics = count_if(
        myString.begin(),
        myString.end(),
        [](auto&& character)
        {
            return static_cast<bool>(isalpha(character));
        });
    cout << "The number of alpha numeric characters: " << numberOfAlphaNumerics << endl;

    auto numberOfPunctuationMarks = count_if(
        myString.begin(),
        myString.end(),
        [](auto&& character)
        {
            return static_cast<bool>(ispunct(character));
        });
    cout << "The number of punctuation marks: " << numberOfPunctuationMarks << endl;

    auto numberOfWhiteSpaceCharacters = count_if(
        myString.begin(),
        myString.end(),
        [](auto&& character)
        {
            return static_cast<bool>(isspace(character));
        });
    cout << "The number of white space characters: " << numberOfWhiteSpaceCharacters << endl;

    return 0;
}
