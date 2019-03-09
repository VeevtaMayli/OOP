#include "pch.h"
#include "lw2/html_encode/html_encode.h"

TEST_CASE("HtmlEncode() return line from argument with encoded html entities")
{
	// empty input string
	std::string in;
	std::string out;
	CHECK(HtmlEncode(in) == out);

	// " in input string
	in = "\"";
	out = "&quot;";
	CHECK(HtmlEncode(in) == out);

	// ' in input string
	in = "'";
	out = "&apos;";
	CHECK(HtmlEncode(in) == out);

	// < in input string
	in = "<";
	out = "&lt;";
	CHECK(HtmlEncode(in) == out);

	// > in input string
	in = ">";
	out = "&gt;";
	CHECK(HtmlEncode(in) == out);

	// & in input string
	in = "&";
	out = "&amp;";
	CHECK(HtmlEncode(in) == out);

	// all above characters in input string
	in = "Cat <says> \"Meow\". M&M's.";
	out = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s.";
	CHECK(HtmlEncode(in) == out);
}
