#include "pch.h"
#include "html_encode.h"

using namespace std;

void HtmlEncodeStream(istream& input, ostream& output)
{
	string line;

	while (getline(input, line))
	{
		output << HtmlEncode(line) << endl;
	}
}

int main()
{
	HtmlEncodeStream(cin, cout);
	return 0;
}
