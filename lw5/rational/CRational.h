#pragma once
class CRational
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;
	double ToDouble() const;

	CRational const operator-() const;
	CRational const operator+() const;
	CRational& operator+=(const CRational& fraction);
	CRational& operator-=(const CRational& fraction);
	CRational& operator*=(const CRational& fraction);
	CRational& operator/=(const CRational& fraction);

private:
	int m_numerator, m_denominator;
};

CRational const operator+(const CRational& fraction1, const CRational& fraction2);
CRational const operator-(const CRational& fraction1, const CRational& fraction2);
CRational const operator*(const CRational& fraction1, const CRational& fraction2);
CRational const operator/(const CRational& fraction1, const CRational& fraction2);

bool const operator==(const CRational& fraction1, const CRational& fraction2);
bool const operator!=(const CRational& fraction1, const CRational& fraction2);
bool const operator<(const CRational& fraction1, const CRational& fraction2);
bool const operator>(const CRational& fraction1, const CRational& fraction2);
bool const operator<=(const CRational& fraction1, const CRational& fraction2);
bool const operator>=(const CRational& fraction1, const CRational& fraction2);

std::ostream& operator<<(std::ostream& strm, const CRational& fraction);
std::istream& operator>>(std::istream& strm, const CRational& fraction);