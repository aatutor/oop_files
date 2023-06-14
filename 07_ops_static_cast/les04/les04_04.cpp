#include <iostream>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int&& rvalRef{ 2 + 3 };
	rvalRef += 3;
	std::cout << rvalRef << '\n';

	int&& res{ max(3, 5) };
	res += max(6, 4);
	std::cout << res << '\n';

	int x{ 42 };

	//	��������� ������ ���������������� ����������!
	//int&& rvalBad{ x }; /* ���������� ���������������� rvalue ������ lvalue ��������. */
	//int&& rvalBad1{ res }; /* rvalue ������ ���� �������� lvalue �������� */
	int& lvalRef{ res };
	std::cout << lvalRef << '\n';

	return 0;
}