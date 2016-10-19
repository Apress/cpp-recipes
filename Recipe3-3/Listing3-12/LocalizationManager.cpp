#include "LocalizationManager.h"

#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

namespace Localization
{
    Manager::Manager()
    {
	ifstream csvStringFile{ "strings.csv"s };

	assert(csvStringFile);
	if (csvStringFile)
	{
	    while (!csvStringFile.eof())
	    {
		string line;
		getline(csvStringFile, line);

		if (line.size() > 0)
		{
                    // Create a stringstream for the line
		    stringstream lineStream{ line };

		    // Use the line stream to read in the string id
		    string stringIdText;
		    getline(lineStream, stringIdText, ',');
		   
		    stringstream idStream{ stringIdText }; 
		    uint32_t stringId;
		    idStream >> stringId;

		    // Loop over the line and read in each string
		    uint32_t languageId = 0;
		    string stringText;
		    while (getline(lineStream, stringText, ','))
		    {
			m_StringPacks[languageId++][stringId] = stringText;
		    }
		}
	    }
	}

	SetLanguage(Languages::EN_US);
    }

    void Manager::SetLanguage(Languages language)
    {
        m_CurrentStringPack = &(m_StringPacks[static_cast<uint32_t>(language)]);
    }

    std::string Manager::GetString(StringID stringId) const
    {
	stringstream resultStream;
	resultStream << "!!!"s;
	resultStream << stringId;
	resultStream << "!!!"s;
	string result{ resultStream.str() };

	auto iter = m_CurrentStringPack->find(stringId);
	if (iter != m_CurrentStringPack->end())
	{
	    result = iter->second;
	}

	return result;
    }
}
