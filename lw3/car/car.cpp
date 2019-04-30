#include "pch.h"
#include "car.h"

using namespace std;

map<int, TransmitionSpeedRange> CCar::m_transmition = { { -1, { 0, 20 } },
	{ 0, { 0, 150 } },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } } };

bool CCar::TurnOnEngine()
{
	m_engineState = EngineState::ON;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (m_engineState == EngineState::ON && m_gear == 0 && m_speed == 0)
	{
		m_engineState = EngineState::OFF;
		return true;
	}
	return false;
}

bool CCar::CanShiftGear(const int gear) const
{
	if (m_engineState == EngineState::OFF)
	{
		return false;
	}
	if (gear > 0 && m_direction == Direction::BACK || gear < 0 && m_direction != Direction::NONE)
	{
		return false;
	}
	try
	{
		TransmitionSpeedRange range = m_transmition.at(gear);
		if (range.min > m_speed || range.max < m_speed)
		{
			return false;
		}
	}
	catch (std::out_of_range const& e)
	{
		e.what();
		return false;
	}
	return true;
}

bool CCar::CanSetSpeed(const unsigned int speed) const
{
	if (m_engineState == EngineState::OFF)
	{
		return false;
	}
	if (m_gear == 0 && speed > m_speed)
	{
		return false;
	}
	if (m_transmition[m_gear].min > speed || m_transmition[m_gear].max < speed)
	{
		return false;
	}
	return true;
}

void CCar::ChangeDirection()
{
	if (m_speed == 0)
	{
		m_direction = Direction::NONE;
	}
	if (m_speed > 0 && m_gear > 0)
	{
		m_direction = Direction::FORWARD;
	}
	if (m_speed > 0 && m_gear < 0)
	{
		m_direction = Direction::FORWARD;
	}
}

bool CCar::SetGear(const int gear)
{
	if (!CanShiftGear(gear))
	{
		return false;
	}
	m_gear = gear;
	return true;
}

bool CCar::SetSpeed(const int speed)
{
	if (!CanSetSpeed(speed))
	{
		return false;
	}
	m_speed = speed;
	ChangeDirection();
	return true;
}

int CCar::GetGear() const
{
	return m_gear;
}

unsigned int CCar::GetSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

EngineState CCar::GetEngineState() const
{
	return m_engineState;
}
