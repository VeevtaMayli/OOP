#pragma once

#include <map>

struct TransmitionSpeedRange
{
	unsigned int min;
	unsigned int max;

};

enum class EngineState
{
	ON,
	OFF
};

enum class Direction
{
	FORWARD,
	BACK,
	NONE
};

class CCar
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const int gear);
	bool SetSpeed(const int speed);
	int GetGear() const;
	int GetSpeed() const;
	Direction GetDirection() const;
	EngineState GetEngineState() const;

private:
	EngineState m_engineState = EngineState::OFF;
	Direction m_direction = Direction::NONE;
	int m_speed = 0;
	int m_gear = 0;
	static std::map<int, TransmitionSpeedRange> m_transmition;
};
