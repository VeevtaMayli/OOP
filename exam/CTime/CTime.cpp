#include "pch.h"
#include "CTime.h"

bool IsCorrectTime(int hours, int minutes, int seconds)
{
	return (hours >= 0 && hours < HOURS_BOUND)
		&& (minutes >= 0 && minutes < MINUTES_BOUND)
		&& (seconds >= 0 && seconds < SECONDS_BOUND);
}

CTime::CTime(int hours, int minutes, int seconds)
{
	if (IsCorrectTime(hours, minutes, seconds))
	{
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}
	else
	{
		throw(std::invalid_argument("Time in range 00:00:00 - 23:59:59"));
	}
}

int CTime::GetHours() const
{
	return m_hours;
}

int CTime::GetMinutes() const
{
	return m_minutes;
}

int CTime::GetSeconds() const
{
	return m_seconds;
}

std::string CTime::ToString() const
{
	return (GetHours() < 10 ? "0" : "") + std::to_string(GetHours())
		+ ":" + (GetMinutes() < 10 ? "0" : "") + std::to_string(GetMinutes())
		+ ":" + (GetSeconds() < 10 ? "0" : "") + std::to_string(GetSeconds());
}

CTime& CTime::operator+=(const CTime& time)
{
	return *this = *this + time;
}

CTime& CTime::operator-=(const CTime& time)
{
	return *this = *this - time;
}

const CTime CTime::operator+(const CTime& time) const
{
	int totalSeconds = GetSeconds() + time.GetSeconds();
	int seconds = totalSeconds % (SECONDS_BOUND);
	int totalMinutes = GetMinutes() + time.GetMinutes() + totalSeconds / (SECONDS_BOUND);
	int minutes = totalMinutes % (MINUTES_BOUND);
	int totalHours= GetHours() + time.GetHours() + totalMinutes / (MINUTES_BOUND);
	int hours = totalHours % (HOURS_BOUND);
	
	return CTime(hours, minutes, seconds);
}

const CTime CTime::operator-(const CTime& time) const
{
	int argTimeInSeconds = time.GetSeconds() + (time.GetMinutes() + time.GetHours() * MINUTES_BOUND) * SECONDS_BOUND;
	int timeInSeconds = GetSeconds() + (GetMinutes() + GetHours() * MINUTES_BOUND) * SECONDS_BOUND;
	int resultTimeInSeconds = timeInSeconds - argTimeInSeconds;
	if (resultTimeInSeconds < 0)
	{
		resultTimeInSeconds += SECONDS_BOUND * MINUTES_BOUND * HOURS_BOUND;
	}

	int seconds = resultTimeInSeconds % SECONDS_BOUND;
	int minutes = (resultTimeInSeconds / SECONDS_BOUND) % MINUTES_BOUND;
	int hours = (resultTimeInSeconds / SECONDS_BOUND / MINUTES_BOUND) % HOURS_BOUND;

	return CTime(hours, minutes, seconds);
}

std::ostream& operator<<(std::ostream& strm, const CTime& time)
{
	strm << time.ToString() << std::endl;
	return strm;
}
