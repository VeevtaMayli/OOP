#pragma once

#include <map>

using TranslationStorage = std::multimap<std::string, std::string>;

class Dictionary
{
public:
	Dictionary();
	Dictionary(const std::string& fileName);
	std::string Translate(const std::string& word) const;
	void AddTranslation(const std::string& word, const std::string& translation);
	bool Save() const;
	bool Save(const std::string& fileName) const;
	bool WasChanged() const;

private:
	void ReadFromFile(std::istream& input);
	void StoreToFile(std::ostream& output) const;
	std::string ToLower(const std::string& str) const;
	void InsertIntoDictionary(const std::string& word, const std::string& translation);
	bool TranslationExists(const std::string& word, const std::string& translation);

	TranslationStorage m_storage;
	const std::string m_dictionaryFileName;
	bool m_wasChanged = false;
};
