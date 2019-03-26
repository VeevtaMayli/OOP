#include "pch.h"
#include "dictionary.h"
#include <Windows.h>

using namespace std;

bool ParseCommandLine(int argc, char* argv[], string& fileName)
{
	if (argc == 2)
	{
		fileName = argv[1];
		ifstream file(fileName);
		return file.is_open();
	}
	return true;
}

void translateWithDictonary(Dictionary& dictionary)
{
	string input;
	while (getline(cin, input))
	{
		if (input.empty())
		{
			continue;
		}
		if (input == "...")
		{
			break;
		}
		string translation = dictionary.Translate(input);
		if (translation.empty())
		{
			cout << "������� ��� �" << input << "� �����������. ������� ������� ��� ������ ������ ��� ������." << endl;
			string word = input;
			if (getline(cin, input) && !input.empty())
			{
				dictionary.AddTranslation(word, input);
				cout << "�" << word << "� ��������� � ������� ��� �" << input << endl;
			}
		}
		else
		{
			cout << translation << endl;
		}
	}
}

void saveChanges(const Dictionary& dictionary)
{
	string input;
	cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������." << endl;
	if (!(getline(cin, input)))
	{
		return;
	}
	if (!(input == "Y" || input == "y"))
	{
		return;
	}
	if (!dictionary.hasExternalFile())
	{
		cout << "������� ��� ����� ��� ���������� �������." << endl;
		while (getline(cin, input))
		{
			if (!input.empty())
			{
				break;
			}
		}
	}
	if (dictionary.Save(input))
	{
		cout << "��������� ���������. �� ��������." << endl;
	}
	else
	{
		cout << "�� ������� ��������� ���������." << endl;
	}
}

void Dialog(Dictionary& dictionary)
{
	cout << "������� �����, ������� �������� ������� ������. ��� ������ �� ��������� ������� �...�" << endl;
	translateWithDictonary(dictionary);	
	if (dictionary.WasChanged())
	{
		saveChanges(dictionary);
	}
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string dictionaryFileName;
	if (!ParseCommandLine(argc, argv, dictionaryFileName))
	{
		return 1;
	}
	cout << dictionaryFileName << endl;
	Dictionary dictionary(dictionaryFileName);
	Dialog(dictionary);
	return 0;
}
