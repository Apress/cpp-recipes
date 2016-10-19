#pragma once

#include <array>
#include <cinttypes>
#include <string>
#include <unordered_map>

namespace Localization
{
    using StringID = int32_t;

    enum class Languages
    {
	EN_US,
	EN_GB,
	Number
    };

    const StringID STRING_COLOR{ 0 };
    const StringID STRING_FLAVOR{ 1 };
    const StringID STRING_NAME{ 2 };

    class Manager
    {
    private:
	using Strings = std::unordered_map<StringID, std::string>;
	using StringPacks =
	    std::array<Strings, static_cast<size_t>(Languages::Number)>;

	StringPacks m_StringPacks;
	Strings* m_CurrentStringPack{ nullptr };

	uint32_t m_LanguageIndex;

    public:
	Manager();

	void SetLanguage(Languages language);

	std::string GetString(StringID stringId) const;
    };
}
