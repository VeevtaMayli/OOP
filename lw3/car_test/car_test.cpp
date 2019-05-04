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
				//ExpectCorrectState(car, { EngineState::ON, 0, 0, Direction::NONE });
				ExpectOperationSuccess(car, [](CCar& car) { return car.TurnOnEngine(); }, {EngineState::ON, 0, 0, Direction::NONE});
			}
		}
		AND_WHEN("car is turn off")
		{
			car.TurnOnEngine();
			THEN("its engine becomes turned off")
			{
				ExpectOperationSuccess(car, [](CCar& car) { return car.TurnOffEngine(); }, { EngineState::OFF, 0, 0, Direction::NONE });
			}
		}
		AND_WHEN("car has a gear and moves")
		{
			car.TurnOnEngine();
			car.SetGear(1);
			car.SetSpeed(10);
			THEN("its engine can not be turned off")
			{
				ExpectOperationFailure(car, [](CCar& car) { return car.TurnOffEngine(); });
			}
		}
	}
}

SCENARIO("")