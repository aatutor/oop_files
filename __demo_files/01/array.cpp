#include <iostream>
#include <math.h>

double Length(int point[2])
{
	double x2 = point[0] * point[0];
	double y2 = point[1] * point[1];
	
	double result = sqrt(x2 + y2);
	return result;
}

int* Sum(int point1[2], int point2[2]) 
{
	// v1
	int* result = new int[2];
	result[0] = point1[0] + point2[0];
	result[1] = point1[1] + point2[1];
	return result;

	// v2
	// int* res = new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
	// return res;

	// v3
	// return new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
}

char* GetString(int point[2]) 
{
	char* str = new char[100];
	sprintf(str, "(%d, %d)", point[0], point[1]);
	return str;
}

void Print(int point[2]) 
{
	std::cout <<"("<< point[0] <<","<< point[1] <<")\n";
}

void Test() 
{
	using namespace std;
	{
		int arrPoint[2]{3, 4};
		Print(arrPoint);
		//cout << GetString(arrPoint) << endl;
	}
	{
		int point1[2]{1, 2};
		int point2[2]{3, 5};
		int* resultPoint = Sum(point1, point2);
		Print(resultPoint);
	}
	{
		int arrPoint[2]{3, 4};
		Print(arrPoint);
		cout <<"Len = "<< Length(arrPoint) << endl;
	}
}

int main ()
{
	Test();
	//Menu();
	
    return 0;
}
