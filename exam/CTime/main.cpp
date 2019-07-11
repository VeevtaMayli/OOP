#include "pch.h"
#include "CTime.h"

int main()
{
	CTime time1(23, 59, 17);
	CTime time2(01, 12, 13);
	CTime time = time1 + time2;
	std::cout << time1.ToString() << std::endl
		<< time2.ToString() << std::endl
		<< time.ToString() << std::endl << std::endl;

	CTime time3(00, 15, 25);
	CTime time4(01, 16, 25);
	time = time3 - time4;
	std::cout << time3.ToString() << std::endl
			  << time4.ToString() << std::endl
			  << time.ToString() << std::endl;
	return 0;
}
