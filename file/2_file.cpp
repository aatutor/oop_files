#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
using namespace std;

//Функция, выводящая на экран строку
void RussianMessage(const char *str)
{
	char message[100];
	//перевод строки из кодировки Windows (1251)
	CharToOemA(str, message);//в кодировку MS DOS (866)
	cout << message;// .cpp должен быть в кодировке 1251
}

void srch(string* name);
void srch(const char* name);

struct Man {
	char str[255];
	int age;
};

int main()
{
	Man src[2]{
		{"Ivan", 35},
		{"Petr", 18}
	};
	Man dest[2];

	string fileName = "test.txt";

	FILE* file = fopen(fileName.c_str(), "w");
	if (!file)
		return 1;
	fwrite(src, sizeof(Man), 2, file);
	fclose(file);

#ifdef SRC
	srch("test");
	rename("test.txt", "new.txt");
	srch("new");
	fileName = "new.txt";
#endif

	file = fopen(fileName.c_str(), "r");
	if (!file)
		return 1;
	fread(dest, sizeof(Man), 2, file);
	fclose(file);

#ifdef SRC
	remove("new.txt");
	srch("new.txt");
#endif

	cout << "name: " << dest[0].str
		<< "\nage: " << dest[0].age << endl;
	cout << "name: " << dest[1].str
		<< "\nage: " << dest[1].age << endl;

#ifdef SRC
	srch("");
#endif

	return 0;
}

void srch(const char* name) {
	srch(new string{ name });
}
void srch(string* name) {
	_finddata_t* fileInfo = new _finddata_t;
	name->append("*");
	long done = _findfirst(name->c_str(), fileInfo);

	int canWeWork = done;
	int count = 0;
	while (canWeWork != -1) {
		count++;
		if (fileInfo->attrib == _A_SUBDIR)
			cout << fileInfo->size << " ";
		cout << fileInfo->name << endl;
		canWeWork = _findnext(done, fileInfo);
	}
	cout << "Count: " << count << endl;

	_findclose(done);
	delete fileInfo;
}