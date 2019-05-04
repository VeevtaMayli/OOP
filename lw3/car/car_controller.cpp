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

bool CCarController::Info(std::istream& args)
{
	m_output << "Engine state:" << ToString(m_car.GetEngineState()) << endl;
	m_output << "Gear:" << m_car.GetGear() << endl;
	m_output << "Speed:" << m_car.GetSpeed() << endl;
	m_output << "Direction:" << ToString(m_car.GetDirection()) << endl;
	return true;
}

bool CCarController::EngineOn(std::istream& args)
{
	return m_car.TurnOnEngine();
}

bool CCarController::EngineOff(std::istream& args)
{
	return m_car.TurnOffEngine();
}

bool CCarController::SetGear(std::istream& args)
{
	return true;
}

bool CCarController::SetSpeed(std::istream& args)
{
	return false;
}

std::string CCarController::ToString(EngineState state)
{
	return state == EngineState::OFF ? "OFF" : "ON";
}

std::string CCarController::ToString(Direction direction)
{
	return direction == Direction::NONE ? "NONE" : (direction == Direction::FORWARD ? "FORWARD" : "BACK");
}


