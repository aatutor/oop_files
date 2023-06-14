#include <iostream>

// funA overloads with rvalue overload
void funA(int& val)
{
	std::cout << "funA() called for int&\n";
}

void funA(const int& val)
{
	std::cout << "funA() called for const int&\n";
}

void funA(int&& val)
{
	std::cout << "funA() called for int&&\n";
}

// funB overloads without rvalue overload
void funB(int& val)
{
	std::cout << "funB() called for int&\n";
}

void funB(const int& val)
{
	std::cout << "funB() called for const int&\n";
}

int main()
{
	int val{ 42 };
	const int cVal{ 26 };

	std::cout << "funA overloads with rvalue overload:\n";
	std::cout << "lvalue\n";
	funA(val); // lvalue -> int&
	std::cout << "const lvalue\n";
	funA(cVal); // const lvalue -> const int&
	std::cout << "rvalue\n";
	funA(80 + 1); // rvalue -> int&&
	std::cout << "moved lvalue\n";
	funA(std::move(val)); // moved lvalue -> int&&

	std::cout << '\n';

	std::cout << "funB overloads without rvalue overload:\n";
	std::cout << "lvalue\n";
	funB(val); // lvalue -> int&
	std::cout << "const lvalue\n";
	funB(cVal); // const lvalue -> const int&
	std::cout << "rvalue\n";
	funB(80 + 1); // rvalue -> const int&
	std::cout << "moved lvalue\n";
	funB(std::move(val)); // moved lvalue ->const int&

	return 0;
}