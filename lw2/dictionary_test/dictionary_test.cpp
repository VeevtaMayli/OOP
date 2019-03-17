#include "lw2/dictionary/dictionary.h"
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <locale>

TEST_CASE("AddTranslation() adds only new translation to dictionary")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;

	dictionary.AddTranslation("book", "книга");
	CHECK(dictionary.Translate("book") == "книга");
	CHECK(dictionary.Translate("книга") == "book");
}

TEST_CASE("Translate() returns all translations of input word if it is in dictionary; otherwise empty string")
{
	Dictionary dictionary;

	CHECK(dictionary.Translate("") == "");
	CHECK(dictionary.Translate("book") == "");
}
