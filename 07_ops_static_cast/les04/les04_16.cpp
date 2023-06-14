#include <iostream>
#include <cassert>

class MedalRow
{
	char country[4];
	int medals[3];
public:
	/* определяем константы для удобного и однозначного доступа к элементам массива */
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONSE{ 2 };

	MedalRow(const char* countryP, const int* medalsP)
	{
		strcpy_s(country, 4, countryP ? countryP : "NON");

		for (int i{ 0 }; i < 3; ++i)
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}
	MedalRow() : MedalRow(nullptr, nullptr) {}
	MedalRow& setCountry(const char* countryP)
	{
		if (countryP)
		{
			strcpy_s(country, 4, countryP);
		}
		return *this;
	}
	const char* getCountry()const { return country; }
	int& operator[](int idx)
	{
		assert((idx >= 0 and idx < 3) and "Index out of range!");
		return medals[idx];
	}
	int operator[](int idx)const
	{
		assert((idx >= 0 and idx < 3) and "Index out of range!");
		return medals[idx];
	}
	void print()const
	{
		std::cout << '[' << country << "]-( ";
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << medals[i];
			if (i < 2) { std::cout << '\t'; }
		}
		std::cout << " )\n";
	}
};

int main()
{
	MedalRow mr;
	mr.setCountry("UKR");
	std::cout << "Country is: " << mr.getCountry() << '\n';
	mr[MedalRow::GOLD] = 3;
	mr[MedalRow::BRONSE] = 2;
	mr[MedalRow::SILVER] = 4;

	/* Создаем строку-копию, на основе mr */
	MedalRow mr1{ mr };

	/* Убеждаемся, что создалась копия */
	mr1.print();

	/* Модифицируем значения строки-копии, выводим ее на экран*/
	mr1[MedalRow::GOLD] = 11;
	mr1[MedalRow::BRONSE] = 22;
	mr1[MedalRow::SILVER] = 33;
	mr1.print();

	/* Убеждаемся, что оригинал остался не модифицированным */
	mr.print();

	return 0;
}