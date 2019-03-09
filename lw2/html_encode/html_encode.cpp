#include "pch.h"
#include "html_encode.h"

using namespace std;

const vector<pair<char, string>> HTML_ENTITIES = {
	{ '"', "&quot;" },
	{ '\'', "&apos;" },
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '&', "&amp;" }
};

string HtmlEncodeChar(const char ch)
{
	for (auto essence : HTML_ENTITIES)
	{
		if (ch == essence.first)
		{
			return essence.second;
		}
	}
	return string(1, ch);
}

string HtmlEncode(string const& text)
{
	string encodedLine;
	for (auto ch : text)
	{
		encodedLine.append(HtmlEncodeChar(ch));
	}
	return encodedLine;
}
