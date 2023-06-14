#include <iostream>
class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(DynArray&& object)
		: arr{ object.arr }, size{ object.size }
	{
		object.arr = nullptr;
		object.size = 0;
		std::cout << "DynArr move constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray& operator=(DynArray&& object)
	{
		if (!(this == &object))
		{
			delete arr;

			arr = object.arr;
			size = object.size;

			object.arr = nullptr;
			object.size = 0;

		}
		std::cout << "DynArr move assigned for "
			<< size << " elements, for " << this
			<< '\n';

		return *this;
	}
	int getElem(int idx)const { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print()const;
	void randomize();
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for "
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::print()const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

DynArray arrayFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}

int main()
{
	DynArray ar1{ arrayFactory(10) };
	std::cout << "ar1 elements: ";
	ar1.print();

	DynArray ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();

	return 0;
}