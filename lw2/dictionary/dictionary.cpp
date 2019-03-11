#include "pch.h"
#include "dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(const std::string& fileName)
{
}

std::string Dictionary::Translate() const
{
	return std::string();
}

void Dictionary::AddTranslation(const std::string& word, const std::string& translation)
{
}

bool Dictionary::Save() const
{
	return false;
}

bool Dictionary::Save(const std::string& fileName) const
{
	return false;
}

bool Dictionary::WasChanged() const
{
	return false;
}

void Dictionary::ReadFromFile(std::istream& input)
{
}

void Dictionary::SaveToFile(std::ostream& output) const
{
}

std::string Dictionary::ToLower(const std::string& str) const
{
	return std::string();
}

void Dictionary::InsertIntoDictionary(const std::string& word, const std::string& translation)
{
}
