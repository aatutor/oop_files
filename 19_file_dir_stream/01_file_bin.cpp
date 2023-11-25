 #define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

struct Man {
	char str[255];
	int age;
};

void Write()
{
	Man src[2]{
		{"Ivan", 35},
		{"Petr", 18}
	};

	FILE* file = fopen("test.txt", "wb");
	if (!file)
		return;

#if 1
	fwrite(src, sizeof(Man), 2, file);
#else
	fwrite(src, sizeof(src), 1, file);
#endif

	fclose(file);
}

void Read() {
	using namespace std;

	Man dest[2];
	FILE* file = fopen("test.txt", "rb");
	if (!file)
		return;

#if 1
	fread(dest, sizeof(Man), 2, file);
#else
	fread(dest, sizeof(dest), 1, file);
#endif

	fclose(file);

	cout << "name: " << dest[0].str
		<< "\nage: " << dest[0].age << endl;
	cout << "name: " << dest[1].str
		<< "\nage: " << dest[1].age << endl;
}

int main()
{
	Write();
	Read();

	return 0;
}