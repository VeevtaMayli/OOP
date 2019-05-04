#include "pch.h"
#include "lw3/car/car.h"

using namespace std;

struct CarState
{
	EngineState engineState;
	int gear;
	unsigned int speed;
	Direction direction;
};

void ExpectCorrectState(const CCar& car, const CarState& expectedState)
{
	CHECK(car.GetEngineState() == expectedState.engineState);
	CHECK(car.GetGear() == expectedState.gear);
	CHECK(car.GetSpeed() == expectedState.speed);
	CHECK(car.GetDirection() == expectedState.direction);
}

void ExpectOperationSuccess(CCar& car, const function<bool(CCar& car)>& op, CarState expectedCarState)
{
	CHECK(op(car));
	ExpectCorrectState(car, expectedCarState);
}

void ExpectOperationFailure(const CCar& car, const function<bool(CCar& car)>& op)
{
	auto clone(car);
	CHECK(!op(clone));
	CHECK(car.GetEngineState() == clone.GetEngineState());
	CHECK(car.GetGear() == clone.GetGear());
	CHECK(car.GetSpeed() == clone.GetSpeed());
	CHECK(car.GetDirection() == clone.GetDirection());
}

SCENARIO("Car can be turned on and off")
{
	GIVEN("A turned off car")
	{
		CCar car;
		WHEN("car is turn on for the first time")
		{
			THEN("its engine becomes turned on")
			{
				ExpectOperationSuccess(car, [](CCar& car) { return car.TurnOnEngine(); }, { EngineState::ON, 0, 0, Direction::NONE });
			}
		}
	}
	AND_GIVEN("A turned on car")
	{
		CCar car;
		car.TurnOnEngine();
		WHEN("try to turn off a car")
		{
			THEN("its engine becomes turned off")
			{
				ExpectOperationSuccess(car, [](CCar& car) { return car.TurnOffEngine(); }, { EngineState::OFF, 0, 0, Direction::NONE });
			}
		}
		AND_WHEN("car has a gear and moves")
		{
			CHECK(car.SetGear(1));
			CHECK(car.SetSpeed(10));
			THEN("its engine can not be turned off")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.TurnOffEngine(); });

				car.SetSpeed(0);
				car.SetGear(0);
				ExpectOperationSuccess(car, [](CCar& car) { return car.TurnOffEngine(); }, { EngineState::OFF, 0, 0, Direction::NONE });
			}
		}
	}
}

SCENARIO("Shifting gear")
{
	GIVEN("A turned off car")
	{
		CCar car;
		WHEN("try to set any gear")
		{
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(-1); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(0); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(1); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(2); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(3); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(4); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(5); });
			}
		}
		WHEN("try to set any speed")
		{
			THEN("car reports error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetSpeed(1); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetSpeed(150); });
			}
		}
	}
	AND_GIVEN("A turned on car in neutral gear")
	{
		CCar car;
		car.TurnOnEngine();
		WHEN("try to set non-existent gear, not in [-1, 5]")
		{
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(-2); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(6); });
			}
		}
		AND_WHEN("try to set gear when speed not in allowed range")
		{
			CHECK(car.SetGear(1));
			CHECK(car.SetSpeed(19));
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(2); });

				CHECK(car.SetSpeed(25));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(2); }, { EngineState::ON, 2, 25, Direction::FORWARD });

				CHECK(car.SetSpeed(31));
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(1); });

				CHECK(car.SetSpeed(25));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(1); }, { EngineState::ON, 1, 25, Direction::FORWARD });
			}

			CHECK(car.SetSpeed(25));
			CHECK(car.SetGear(2));
			CHECK(car.SetSpeed(29));
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(3); });

				CHECK(car.SetSpeed(35));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(3); }, { EngineState::ON, 3, 35, Direction::FORWARD });

				CHECK(car.SetSpeed(51));
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(2); });

				CHECK(car.SetSpeed(35));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(2); }, { EngineState::ON, 2, 35, Direction::FORWARD });
			}

			CHECK(car.SetSpeed(35));
			CHECK(car.SetGear(3));
			CHECK(car.SetSpeed(39));
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(4); });

				CHECK(car.SetSpeed(45));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(4); }, { EngineState::ON, 4, 45, Direction::FORWARD });

				CHECK(car.SetSpeed(61));
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(3); });

				CHECK(car.SetSpeed(45));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(3); }, { EngineState::ON, 3, 45, Direction::FORWARD });
			}

			CHECK(car.SetSpeed(45));
			CHECK(car.SetGear(4));
			CHECK(car.SetSpeed(49));
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(5); });

				CHECK(car.SetSpeed(65));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(5); }, { EngineState::ON, 5, 65, Direction::FORWARD });

				CHECK(car.SetSpeed(91));
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(4); });

				CHECK(car.SetSpeed(65));
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(4); }, { EngineState::ON, 4, 65, Direction::FORWARD });
			}
		}
	}
}

SCENARIO("Changing direction is possible only when stopping ")
{
	GIVEN("A car is moving back in neutral gear")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.SetGear(-1));
		CHECK(car.SetSpeed(10));
		CHECK(car.SetGear(0));
		WHEN("try to set first gear")
		{
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(1); });
			}
		}
		AND_WHEN("try to set reverse gear")
		{
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetGear(-1); });
			}
		}
		AND_WHEN("after car stopping try to set this gears")
		{
			car.SetSpeed(0);
			THEN("gear is shifted")
			{
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(1); }, { EngineState::ON, 1, 0, Direction::NONE });
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetGear(-1); }, { EngineState::ON, -1, 0, Direction::NONE });
			}
		}
		AND_WHEN("try to increase speed")
		{
			THEN("car reports an error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetSpeed(15); });
				ExpectOperationSuccess(car, [](CCar& car) { return car.SetSpeed(5); }, { EngineState::ON, 0, 5, Direction::BACK });
			}
		}
	}
}

SCENARIO("Changing speed not in allowed range for current gear")
{
	GIVEN("Car moves forward in gear")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.SetGear(1));
		CHECK(car.SetSpeed(25));
		CHECK(car.SetGear(2));
		WHEN("try to set forbidden speed")
		{
			THEN("car reports error")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.SetSpeed(19); });
				ExpectOperationFailure(car, [](CCar& car) { return car.SetSpeed(51); });
			}
		}
	}
}
