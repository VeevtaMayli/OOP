#pragma once

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

enum class Error
{
	NO_ERROR,
	ENGINE_IS_OFF,
	GEAR_NOT_EXISTS,
	SPEED_IS_NOT_ALLOWED,
	SPEED_CAN_DECREASE_ONLY,
	CAR_IS_MOVING
};

class CCar
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const int gear);
	bool SetSpeed(const int speed);
	int GetGear() const;
	unsigned int GetSpeed() const;
	Direction GetDirection() const;
	EngineState GetEngineState() const;

private:
	Error CanShiftGear(const int gear) const;
	Error CanSetSpeed(const unsigned int speed) const;
	void ChangeDirection();
	bool MakeError(const Error err);

	EngineState m_engineState = EngineState::OFF;
	Direction m_direction = Direction::NONE;
	unsigned int m_speed = 0;
	int m_gear = 0;
	Error m_error = Error::NO_ERROR;
	static std::map<int, TransmitionSpeedRange> m_transmition;
};
