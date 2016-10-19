#include "LocalizationManager.h"

#include <cassert>
#include <fstream>
#include "rapidxml.hpp"
#include <sstream>

using namespace std;

namespace Localization
{
    Manager::Manager()
    {
	ifstream xmlStringFile{ "strings.xml"s };
        xmlStringFile.seekg(0, ios::end);
	uint32_t size{ static_cast<uint32_t>(xmlStringFile.tellg()) + 1 };
	char* buffer{ new char[size]{} };
	xmlStringFile.seekg(0, ios::beg);
	xmlStringFile.read(buffer, size);
	xmlStringFile.close();

        rapidxml::xml_document<> document;
	document.parse<0>(buffer);

	rapidxml::xml_node<>* workbook{ document.first_node("Workbook") };
	if (workbook != nullptr)
	{
            rapidxml::xml_node<>* worksheet{ workbook->first_node("Worksheet") };
            if (worksheet != nullptr)
            {
	        rapidxml::xml_node<>* table{ worksheet->first_node("Table") };
	        if (table != nullptr)
	        {
		    rapidxml::xml_node<>* row{ table->first_node("Row") };
		    while (row != nullptr)
		    {
	                uint32_t stringId{ UINT32_MAX };

 		        rapidxml::xml_node<>* cell{ row->first_node("Cell") };
		        if (cell != nullptr)
		        {
		            rapidxml::xml_node<>* data{ cell->first_node("Data") };
			    if (data != nullptr)
			    {
			        stringId = static_cast<uint32_t>(atoi(data->value()));
			    }
		        }

		        if (stringId != UINT32_MAX)
		        {
			    uint32_t languageIndex{ 0 };

			    cell = cell->next_sibling("Cell");
			    while (cell != nullptr)
			    {
			        rapidxml::xml_node<>* data = cell->first_node("Data");
			        if (data != nullptr)
			        {
				    m_StringPacks[languageIndex++][stringId] = data->value();
			        }

                                cell = cell->next_sibling("Cell");
			    }
		        }

		        row = row->next_sibling("Row");
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
