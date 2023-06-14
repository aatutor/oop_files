#include <iostream>

class Dyn2DArr
{
	int sizeY;
	int sizeX;
public:
	int** data;
	Dyn2DArr(int sizeYP, int sizeXP)
		: sizeY{ sizeYP }, sizeX{ sizeXP }, data{ new int* [sizeYP] }
	{
		for (int y{ 0 }; y < sizeY; ++y)
		{
			data[y] = new int[sizeX];
		}
	}

	void print()const
	{
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				std::cout << data[y][x] << '\t';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	~Dyn2DArr()
	{
		for (int y{ 0 }; y < sizeY; ++y)
		{
			delete[] data[y];
		}
		delete[] data;
	}
};

int main()
{
	int rows{ 3 };
	int columns{ 3 };
	int counter{ 1 };

	Dyn2DArr arr2d{ rows, columns };

	for (int y{ 0 }; y < rows; ++y)
	{
		for (int x{ 0 }; x < columns; ++x)
		{
			arr2d.data[y][x] = counter++;
		}
	}

	arr2d.print();

	return 0;
}