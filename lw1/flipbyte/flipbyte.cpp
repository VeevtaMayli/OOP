#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool InRange(const T item, const T min, const T max)
{
	return item >= min && item <= max ? true : false;
}

void FlipByte(uint8_t& byte)
{
	uint8_t flippedByte = 0;
	for (size_t i = 0; i < 8; i++)
	{
		flippedByte >>= 1;
		flippedByte |= (byte << i) & 0x80;
	}
	byte = flippedByte;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: flipbyte.exe <input byte>"
			 << endl;
		return 1;
	}

	unsigned parsedNumber;

	try
	{
		parsedNumber = stoul(argv[1]);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	uint8_t byte;
	if (InRange<unsigned>(parsedNumber, 0, 255))
	{
		byte = static_cast<uint8_t>(parsedNumber);
	}
	else
	{
		cout << "Out of range <0, 255>" << endl;
		return 1;
	}

	FlipByte(byte);

	cout << static_cast<unsigned>(byte) << endl;

	return 0;
}
