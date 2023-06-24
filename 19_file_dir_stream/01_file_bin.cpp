// #define _CRT_SECURE_NO_WARNINGS
/*
	start with:
	g++ main.cpp -D1 -o main
*/

#include <iostream>
#include <io.h>

struct Man {
	char str[255];
	int age;
};

int main()
{
	{
		Man src[2]{
			{"Ivan", 35},
			{"Petr", 18}
		};

		FILE* file = fopen("test.txt", "w");
		if (!file)
			return 1;

		fwrite(src, sizeof(Man), 2, file);
		// fwrite(src, sizeof(src), 1, file);
		
		fclose(file);
	}
	{
		using namespace std;

		Man dest[2];
		FILE* file = fopen("test.txt", "r");
		if (!file)
			return 1;

		fread(dest, sizeof(Man), 2, file);
		// fread(dest, sizeof(dest), 1, file);

		fclose(file);

		cout << "name: " << dest[0].str
			<< "\nage: " << dest[0].age << endl;
		cout << "name: " << dest[1].str
			<< "\nage: " << dest[1].age << endl;
	}

	return 0;
}