#include "pch.h"
#include "dictionary.h"
#include <Windows.h>

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dictionary dictionary;
	std::string str;
	std::cin >> str;
	std::cout << dictionary.ToLower(str);
}
