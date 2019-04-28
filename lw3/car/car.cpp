#include "pch.h"
#include "car.h"

using namespace std;

std::map<int, TransmitionSpeedRange> CCar::m_transmition = { { -1, { 0, 20 } },
	{ 0, { 0, 0 } },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } } };

bool CCar::TurnOnEngine()
{
	return false;
}

bool CCar::TurnOffEngine()
{
	return false;
}

bool CCar::SetGear(const int gear)
{
	return false;
}

bool CCar::SetSpeed(const int speed)
{
	return false;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	return (m_speed != 0) ? ((m_speed > 0) ? Direction::FORWARD : Direction::BACK) : Direction::NONE;
}

EngineState CCar::GetEngineState() const
{
	return m_engineState	;
}
