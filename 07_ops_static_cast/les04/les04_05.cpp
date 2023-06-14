#include <iostream>

int main()
{
	int x{ 42 };
	int&& rvalRef{ std::move(x) };

	std::cout << rvalRef << '\n';

	return 0;
}