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
	return MakeError(Error::NO_ERROR);
}

bool CCar::TurnOffEngine()
{
	if (m_gear == 0 && m_speed == 0)
	{
		m_engineState = EngineState::OFF;
		return MakeError(Error::NO_ERROR);
	}
	return MakeError(Error::CAR_IS_MOVING);
}

Error CCar::CanShiftGear(const int gear) const
{
	if (m_engineState == EngineState::OFF)
	{
		return Error::ENGINE_IS_OFF;
	}
	if (gear > 0 && m_direction == Direction::BACK || gear < 0 && m_direction != Direction::NONE)
	{
		return Error::CAR_IS_MOVING;
	}
	try
	{
		TransmitionSpeedRange range = m_transmition.at(gear);
		if (range.min > m_speed || range.max < m_speed)
		{
			return Error::SPEED_IS_NOT_ALLOWED;
		}
	}
	catch (std::out_of_range)
	{
		return Error::GEAR_NOT_EXISTS;
	}
	return Error::NO_ERROR;
}

Error CCar::CanSetSpeed(const unsigned int speed) const
{
	if (m_engineState == EngineState::OFF)
	{
		return Error::ENGINE_IS_OFF;
	}
	if (m_gear == 0 && speed > m_speed)
	{
		return Error::SPEED_CAN_DECREASE_ONLY;
	}
	if (m_transmition[m_gear].min > speed || m_transmition[m_gear].max < speed)
	{
		return Error::SPEED_IS_NOT_ALLOWED;
	}
	return Error::NO_ERROR;
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
		m_direction = Direction::BACK;
	}
}

bool CCar::MakeError(const Error err)
{
	m_error = err;
	return m_error == Error::NO_ERROR;
}

bool CCar::SetGear(const int gear)
{
	Error err = CanShiftGear(gear);
	if (err == Error::NO_ERROR)
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(const int speed)
{
	Error err = CanSetSpeed(speed);
	if (err == Error::NO_ERROR)
	{
		m_speed = speed;
		ChangeDirection();
	}
	return MakeError(err);
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
