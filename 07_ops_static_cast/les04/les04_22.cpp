#include <iostream>

int cnt()
{
	static int counter{ 0 };
	return counter++;
}

int main()
{
	const int maxCnt{ 5 };

	for (int i{ 0 }; i < maxCnt; ++i)
	{
		std::cout << cnt() << ' ';
	}
	std::cout << '\n';

	return 0;
}