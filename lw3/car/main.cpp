#include "pch.h"
#include "car.h"
#include "car_controller.h"

using namespace std;

int main()
{
	CCar car;
	CCarController carController(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!carController.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}
