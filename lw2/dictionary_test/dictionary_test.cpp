#include "lw2/dictionary/dictionary.h"
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <locale>

TEST_CASE("Translate() returns all translations of input word if it is in dictionary; otherwise empty string")
{
	Dictionary dictionary;

	CHECK(dictionary.Translate("") == "");
	CHECK(dictionary.Translate("book") == "");
}

TEST_CASE("Fill dictionary from file")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary("saved_dictionary.txt");

	CHECK(dictionary.Translate("Кот") == "Cat");
	CHECK(dictionary.Translate("Cat") == "Кот, Кошка");
}

TEST_CASE("AddTranslation() adds only new translation to dictionary, WasChanged() returns true when dictionary was changed")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;
	CHECK(!dictionary.WasChanged());

	dictionary.AddTranslation("book", "книга");
	CHECK(dictionary.WasChanged());

	CHECK(dictionary.Translate("book") == "книга");
	CHECK(dictionary.Translate("книга") == "book");
}

TEST_CASE("Save dictionary to file")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SECTION("save to a new file") {
		Dictionary dictionary;
		dictionary.AddTranslation("book", "книга");
		dictionary.Save("new_dictionary.txt");

		Dictionary savedDictionary("new_dictionary.txt");
		CHECK(savedDictionary.Translate("book") == "книга");
		CHECK(savedDictionary.Translate("книга") == "book");
	}

	SECTION("save to an existing file")
	{
		Dictionary dictionary("saved_dictionary.txt");
		dictionary.AddTranslation("book", "книга");
		dictionary.Save();

		Dictionary savedDictionary("new_dictionary.txt");

		CHECK(savedDictionary.Translate("book") == "книга");
		CHECK(savedDictionary.Translate("книга") == "book");

		CHECK(dictionary.Translate("Кот") == "Cat");
		CHECK(dictionary.Translate("Cat") == "Кот, Кошка");
	}
}