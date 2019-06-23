#include "pch.h"
#include "lw7/FindMaxEx/FindMaxEx.h"

TEST_CASE("FindMaxEx() get vector of int")
{
	int result;
	std::vector<int> v;
	CHECK(!FindMaxEx(v, result, std::less<int>()));

	v = { 5, 3, 7, -2, 6 };
	CHECK(FindMaxEx(v, result, std::less<int>()));
	CHECK(result == 7);
}

TEST_CASE("FindMaxEx() get vector of double")
{
	double result;
	std::vector<double> v = { 1.5, 6.2, 4.0, 6.1 };
	CHECK(FindMaxEx(v, result, std::less<double>()));
	CHECK(result == 6.2);
}

TEST_CASE("FindMaxEx() get vector of string")
{
	std::vector<std::string> v = { "cat", "apple", "dog", "catamaran", "dogma" };
	std::string result;
	CHECK(FindMaxEx(v, result, std::less<std::string>()));
	CHECK(result == "dogma");
}

struct Sportsman
{
	std::string name;
	double height;
	double weight;
};

std::vector<Sportsman> emptyVector;
std::vector<Sportsman> sportsmen = { { "Vasya", 186.5, 100.0 },
	{ "Petya", 190.0, 100.0 },
	{ "Vanya", 190.5, 95.5 },
	{ "Igor", 196.0, 98.5 },
	{ "Semen", 175.0, 110.0 } };

TEST_CASE("FindMaxEx() get vector of sporstmen and return sportsman with max weight")
{
	Sportsman sportsman;
	CHECK(FindMaxEx(sportsmen, sportsman, [](Sportsman const& a, Sportsman const& b) { return a.weight < b.weight; }));
	CHECK(sportsman.name == "Semen");
	CHECK(sportsman.weight == 110.0);
};

TEST_CASE("FindMaxEx() get vector of sportsmen and return sportsman with max height")
{
	Sportsman sportsman;
	CHECK(FindMaxEx(sportsmen, sportsman, [](Sportsman const& a, Sportsman const& b) { return a.height < b.height; }));
	CHECK(sportsman.name == "Igor");
	CHECK(sportsman.height == 196.0);
};