#pragma once
const int HOURS_BOUND = 24;
const int MINUTES_BOUND = 60;
const int SECONDS_BOUND = 60;

class CTime
{
public:
	// ������������ ����� (��:��:��).
	// ���� ����, ������, ��� ������� ������� �� ������� 23:59:59, �������
	// ���������� invalid_argument
	CTime(int hours, int minutes, int seconds);

	// ���������� ���������� ����� (0..23)
	int GetHours() const;

	// ���������� ���������� ����� (0..59)
	int GetMinutes() const;

	// ���������� ���������� ������ (0..59)
	int GetSeconds() const;

	// ���������� ��������� ������������� ������� � ������� ��:��:��
	std::string ToString() const;

	CTime& operator+=(const CTime& time);
	CTime& operator-=(const CTime& time);
	const CTime operator+(const CTime& time) const;
	const CTime operator-(const CTime& time) const;

private:
	int m_hours;
	int m_minutes;
	int m_seconds;
};

std::ostream& operator<<(std::ostream& strm, const CTime& time);

/*
����������� ������ ������ � ������������� ���� ��������. �������� � ��������� ����������� � �������� �����
�������:
	+	���������� ��������� ���������: 23:59:17 + 01:12:13 -> 01:11:30
	-	�������� ��������� ���������: 00:15:25 - 01:16:25 -> 22:59:00
	+=	a += b ���������� a = a + b
	-=	a -= b ���������� a = a - b
	<<	������� ����� � �������� ostream � ������� ��:��:��
*/
