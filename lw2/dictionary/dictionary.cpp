#include "pch.h"
#include "dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(const std::string& fileName)
	: m_dictionaryFileName(fileName)
{
	if (!m_dictionaryFileName.empty())
	{
		std::ifstream input(m_dictionaryFileName);
		if (input.is_open())
		{
			ReadFromFile(input);
		}
	}
}

std::string Dictionary::Translate(const std::string& word) const
{
	auto foundPositions = m_storage.equal_range(word);
	std::string resultStr;
	for (auto it = foundPositions.first; it != foundPositions.second; it++)
	{
		resultStr.empty() ? resultStr.append(it->second) : resultStr.append(", " + it->second);
	}
	return resultStr;
}

void Dictionary::AddTranslation(const std::string& word, const std::string& translation)
{
	std::string lowerWord = ToLower(word);
	std::string lowerTranslation = ToLower(translation);
	InsertIntoDictionary(word, translation);
	InsertIntoDictionary(translation, word);
}

bool Dictionary::Save() const
{
	return Save("");
}

bool Dictionary::Save(const std::string& fileName) const
{
	std::string outputFileName = m_dictionaryFileName.empty() ? fileName : m_dictionaryFileName;
	std::ofstream output(outputFileName);
	if (output.is_open())
	{
		StoreToFile(output);
		return true;
	}
	return false;
}

bool Dictionary::WasChanged() const
{
	return m_wasChanged;
}

void Dictionary::ReadFromFile(std::istream& input)
{
	std::string word, translation;
	while (std::getline(input, word) && std::getline(input, translation))
	{
		AddTranslation(word, translation);
	}
}

void Dictionary::StoreToFile(std::ostream& output) const
{
	for (const auto& it : m_storage)
	{
		output << it.first << std::endl
			   << it.second << std::endl;
	}
}

std::string Dictionary::ToLower(const std::string& str) const
{
	std::string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), tolower);
	return lowerStr;
}

void Dictionary::InsertIntoDictionary(const std::string& word, const std::string& translation)
{
	if (!TranslationExists(word, translation))
	{
		m_storage.emplace(word, translation);
		m_wasChanged = true;
	}
}

bool Dictionary::TranslationExists(const std::string& word, const std::string& translation)
{
	auto foundPositions = m_storage.equal_range(word);
	return std::find_if(foundPositions.first, foundPositions.second, [&translation](auto&& position) {
		return position.second == translation;
	}) != foundPositions.second;
}
