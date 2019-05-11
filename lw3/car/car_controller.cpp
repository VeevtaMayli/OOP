#include "pch.h"
#include "car.h"
#include "car_controller.h"

using namespace std;
using namespace std::placeholders;

CCarController::CCarController(CCar& car, istream& input, ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "Info", bind(&CCarController::Info, this, placeholders::_1) },
		  { "EngineOn", bind(&CCarController::EngineOn, this, placeholders::_1) },
		  { "EngineOff", bind(&CCarController::EngineOff, this, placeholders::_1) },
		  { "SetGear", bind(&CCarController::SetGear, this, placeholders::_1) },
		  { "SetSpeed", bind(&CCarController::SetSpeed, this, placeholders::_1) } })
{
}

bool CCarController::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;
	
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CCarController::Info(istream& args)
{
	m_output << "Engine state: " << ToString(m_car.GetEngineState()) << endl;
	m_output << "Gear: " << m_car.GetGear() << endl;
	m_output << "Speed: " << m_car.GetSpeed() << endl;
	m_output << "Direction: " << ToString(m_car.GetDirection()) << endl;
	return true;
}

bool CCarController::EngineOn(istream& args)
{
	m_car.TurnOnEngine();
	m_output << "Engine turned on" << "." << endl;
	return true;
}

bool CCarController::EngineOff(istream& args)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine turned off" << "." << endl;
	}
	else
	{
		m_output << ErrorHandler(m_car.GetError()) << endl;
	}
	return true;
}

bool CCarController::SetGear(istream& args)
{
	string input;
	args >> input;
	const int gear = stoi(input);
	
	if (m_car.SetGear(gear))
	{
		m_output << "Selected gear " << gear << "." << endl;
	}
	else
	{
		m_output << ErrorHandler(m_car.GetError()) << endl;
	}
	return true;
}

bool CCarController::SetSpeed(istream& args)
{
	string input;
	args >> input;
	const unsigned int speed = stoul(input);

	if (m_car.SetSpeed(speed))
	{
		m_output << "Selected speed " << speed << "." << endl;
	}
	else
	{
		m_output << ErrorHandler(m_car.GetError()) << endl;
	}
	return true;
}

string CCarController::ToString(const EngineState state)
{
	return state == EngineState::OFF ? "OFF" : "ON";
}

string CCarController::ToString(const Direction direction)
{
	return direction == Direction::NONE ? "NONE" : (direction == Direction::FORWARD ? "FORWARD" : "BACK");
}

string CCarController::ErrorHandler(const Error err)
{
	if (err == Error::ENGINE_IS_OFF)
	{
		return "Engine is turned off.";
	}
	else if (err == Error::GEAR_NOT_EXISTS)
	{
		return "Such gear is not exists. Gear must be in [-1, 5].";
	}
	else if (err == Error::SPEED_IS_NOT_ALLOWED)
	{
		return "Incorrect transmition range.";
	}
	else if (err == Error::SPEED_CAN_DECREASE_ONLY)
	{
		return "Speed decrease only in neutral speed.";
	}
	else if (err == Error::CAR_IS_MOVING)
	{
		return "Car moves. Set gear to neutral and speed to 0.";
	}
	else
	{
		return "";
	}
}
