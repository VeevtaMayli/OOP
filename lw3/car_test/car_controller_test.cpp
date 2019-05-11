#include "pch.h"
#include "lw3/car/car.h"
#include "lw3/car/car_controller.h"

using namespace std;

SCENARIO("Car controller cam turn on an engine")
{
	GIVEN("A controller connected to the turned off car")
	{
		CCar car;
		stringstream input, output;
		CCarController controller(car, input, output);

		CHECK(car.GetEngineState() == EngineState::OFF);

		WHEN("user enters 'EngineOn'")
		{
			input << "EngineOn" << endl;
			CHECK(controller.HandleCommand());
			THEN("car engine becomes turned on")
			{
				CHECK(car.GetEngineState() == EngineState::ON);
				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "Engine turned on.\n");
				}
			}
		}
	}
}

SCENARIO("Car controller can set gear and speed")
{
	GIVEN("A controller connected to the turned off car")
	{
		CCar car;
		stringstream input, output;
		CCarController controller(car, input, output);

		CHECK(car.GetEngineState() == EngineState::OFF);

		WHEN("user try set speed")
		{
			input << "SetGear 1" << endl;
			CHECK(controller.HandleCommand());
			THEN("car state remained unchanged")
			{
				CHECK(output.str() == "Engine is turned off.\n");
			}
		}
		AND_WHEN("user try set speed")
		{
			input << "SetSpeed 10" << endl;
			CHECK(controller.HandleCommand());
			THEN("car state remained unchanged")
			{
				CHECK(output.str() == "Engine is turned off.\n");
			}
		}
		AND_GIVEN("turned on car")
		{
			car.TurnOnEngine();
			CHECK(car.GetEngineState() == EngineState::ON);

			WHEN("user enters 'SetGear' command")
			{
				input << "SetGear 1" << endl;
				CHECK(controller.HandleCommand());
				THEN("transmition change gear to 1")
				{
					CHECK(output.str() == "Selected gear 1.\n");
				}
			}
			AND_GIVEN("first gear selected")
			{
				car.SetGear(1);
				WHEN("user enters 'SetSpeed' command")
				{
					input << "SetSpeed 10" << endl;
					CHECK(controller.HandleCommand());
					THEN("car change speed to 10")
					{
						CHECK(output.str() == "Selected speed 10.\n");
					}
				}
			}
		}
	}
}

SCENARIO("Car controller provide information about car")
{
	GIVEN("A controller connected to the turned off car")
	{
		CCar car;
		stringstream input, output;
		CCarController controller(car, input, output);

		CHECK(car.GetEngineState() == EngineState::OFF);

		WHEN("user enters 'Info'")
		{
			input << "Info" << endl;
			CHECK(controller.HandleCommand());
			THEN("user sees car state")
			{
				CHECK(output.str() == "Engine state: OFF\nGear: 0\nSpeed: 0\nDirection: NONE\n");
			}
		}
		AND_GIVEN("turned on car moves in first gear with speed 10")
		{
			car.TurnOnEngine();
			CHECK(car.GetEngineState() == EngineState::ON);
			car.SetGear(1);
			car.SetSpeed(10);

			WHEN("user enters 'Info'")
			{
				input << "Info" << endl;
				CHECK(controller.HandleCommand());
				THEN("user sees car state")
				{
					CHECK(output.str() == "Engine state: ON\nGear: 1\nSpeed: 10\nDirection: FORWARD\n");
				}
			}
        }
	}
}