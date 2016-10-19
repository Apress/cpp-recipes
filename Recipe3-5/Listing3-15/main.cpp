#include <iostream>
#include "LocalizationManager.h"
#include "boost/format.hpp"

using namespace std;

int main()
{
    Localization::Manager localizationManager;
    std::string color{ localizationManager.GetString(Localization::STRING_COLOR) };
    std::cout << "EN_US Localized string: " << color.c_str() << std::endl;

    std::string flavor{ localizationManager.GetString(Localization::STRING_FLAVOR) };
    std::cout << "EN_US Localized string: " << flavor.c_str() << std::endl;

    localizationManager.SetLanguage(Localization::Languages::EN_GB);
    color = localizationManager.GetString(Localization::STRING_COLOR);
    std::cout << "EN_GB Localized string: " << color.c_str() << std::endl;

    flavor = localizationManager.GetString(Localization::STRING_FLAVOR);
    std::cout << "EN_GB Localized string: " << flavor.c_str() << std::endl;

    color = localizationManager.GetString(3);
    std::cout << color.c_str() << std::endl;

    std::cout << "Enter your first name: " << std::endl;
    std::string firstName;
    std::cin >> firstName;

    std::cout << "Enter your surname: " << std::endl;
    std::string surname;
    std::cin >> surname;

    localizationManager.SetLanguage(Localization::Languages::EN_US);
    std::string formattedName{ localizationManager.GetString(Localization::STRING_NAME) };
    formattedName = str( boost::format(formattedName) % firstName % surname );
    std::cout << "You said your name is: " << formattedName << std::endl;

    localizationManager.SetLanguage(Localization::Languages::EN_GB);
    formattedName = localizationManager.GetString(Localization::STRING_NAME);
    formattedName = str(boost::format(formattedName) % firstName % surname);
    std::cout << "You said your name is: " << formattedName << std::endl;

    return 0;
}
