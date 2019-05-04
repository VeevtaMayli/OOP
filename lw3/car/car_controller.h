#pragma once

#include <boost/noncopyable.hpp>

class CCar;

class CCarController : boost::noncopyable
{
public:
	CCarController(CCar& car, std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	bool Info(std::istream& args);
	bool EngineOn(std::istream& args);
	bool EngineOff(std::istream& args);
	bool SetGear(std::istream& args);
	bool SetSpeed(std::istream& args);

	static std::string ToString(EngineState state);
	static std::string ToString(Direction direction);

	CCar& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};
