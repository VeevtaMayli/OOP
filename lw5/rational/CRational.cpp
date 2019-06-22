#include "pch.h"
#include "CRational.h"

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (m_denominator == 0)
	{
		throw std::invalid_argument("The denominator can not be zero");
	}

	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}

	int gcd = std::gcd(m_numerator, m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	return std::pair<int, CRational>(m_numerator / m_denominator, CRational(m_numerator % m_denominator, m_denominator));
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}

CRational& CRational::operator+=(const CRational& fraction)
{
	return *this = *this + fraction;
}

CRational& CRational::operator-=(const CRational& fraction)
{
	return *this = *this - fraction;
}

CRational& CRational::operator*=(const CRational& fraction)
{
	return *this = *this * fraction;
}

CRational& CRational::operator/=(const CRational& fraction)
{
	return *this = *this / fraction;
}

CRational const operator+(const CRational& fraction1, const CRational& fraction2)
{
	int denominator = std::lcm(fraction1.GetDenominator(), fraction2.GetDenominator());
	int numerator = fraction1.GetNumerator() * (denominator / fraction1.GetDenominator()) + fraction2.GetNumerator() * (denominator / fraction2.GetDenominator());
	return CRational(numerator, denominator);
}

CRational const operator-(const CRational& fraction1, const CRational& fraction2)
{
	return fraction1 + (-fraction2);
}

CRational const operator*(const CRational& fraction1, const CRational& fraction2)
{
	return CRational(fraction1.GetNumerator() * fraction2.GetNumerator(), fraction1.GetDenominator() * fraction2.GetDenominator());
}

CRational const operator/(const CRational& fraction1, const CRational& fraction2)
{
	return CRational(fraction1.GetNumerator() * fraction2.GetDenominator(), fraction1.GetDenominator() * fraction2.GetNumerator());
}

bool const operator==(const CRational& fraction1, const CRational& fraction2)
{
	return fraction1.GetNumerator() == fraction2.GetNumerator() && fraction1.GetDenominator() == fraction2.GetDenominator();
}

bool const operator!=(const CRational& fraction1, const CRational& fraction2)
{
	return !(fraction1 == fraction2);
}

bool const operator<(const CRational& fraction1, const CRational& fraction2)
{
	return fraction1.GetNumerator() * fraction2.GetDenominator() < fraction1.GetDenominator() * fraction2.GetNumerator();
}

bool const operator>(const CRational& fraction1, const CRational& fraction2)
{
	return !(fraction1 <= fraction2);
}

bool const operator<=(const CRational& fraction1, const CRational& fraction2)
{
	return fraction1 < fraction2 || fraction1 == fraction2;
}

bool const operator>=(const CRational& fraction1, const CRational& fraction2)
{
	return !(fraction1 < fraction2);
}

std::ostream& operator<<(std::ostream& strm, const CRational& fraction)
{
	strm << fraction.GetNumerator() << '/' << fraction.GetDenominator();
	return strm;
}

std::istream& operator>>(std::istream& strm, CRational& fraction)
{
	int numerator, denominator;
	if (strm >> numerator && strm.get() == '/' && strm >> denominator)
	{
		fraction = CRational(numerator, denominator);
	}
	else
	{
		strm.setstate(std::ios_base::failbit | strm.rdstate());
	}
	return strm;
}
