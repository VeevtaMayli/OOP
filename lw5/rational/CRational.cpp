#include "pch.h"
#include "CRational.h"

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
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

CRational const CRational::operator-() const
{
	return nullptr;
}

CRational const CRational::operator+() const
{
	return nullptr;
}

CRational& CRational::operator+=(const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}

CRational& CRational::operator-=(const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}

CRational& CRational::operator*=(const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}

CRational& CRational::operator/=(const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}

CRational const operator+(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

CRational const operator-(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

CRational const operator*(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

CRational const operator/(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator==(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator!=(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator<(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator>(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator<=(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

bool const operator>=(const CRational& fraction1, const CRational& fraction2)
{
	return nullptr;
}

std::ostream& operator<<(std::ostream& strm, const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}

std::istream& operator>>(std::istream& strm, const CRational& fraction)
{
	// TODO: вставьте здесь оператор return
}
