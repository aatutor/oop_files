#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
using namespace std;

void srch(const char* name);

int main(int argc, char *argv[])
{
	{
		string text = "hello stud";

		FILE* file = fopen("test.txt", "w");
		if (!file)
			return 1;

		fwrite(text.c_str(), sizeof(char), text.length()+1, file);
		fclose(file);
	}

	srch("test");
	// system("pause");
	rename("test.txt", "new.txt");
	srch("new");
	// system("pause");

	{
		char dest[100];
		FILE* file = fopen("new.txt", "r");
		if (!file)
			return 1;
		fread(dest, sizeof(char), 100, file);
		fclose(file);

		cout << dest << endl;
	}

	remove("new.txt");
	srch("new.txt");
	srch("");

	return 0;
}

void srch(string&&);
void srch(const char* name) {
	srch(string{ name });
}

void srch(string&& name) 
{
	_finddata_t* fileInfo = new _finddata_t;
	string path = name + string{"*"};
	long group = _findfirst(path.c_str(), fileInfo);
	// long group = _findfirst(name.append("*").c_str(), fileInfo);
 
	int count = 0;
	int srchResult = group;
	while (srchResult != -1) {
		count++;
		if (fileInfo->attrib & _A_SUBDIR)
			cout << fileInfo->size << " ";
		cout << fileInfo->name << endl;
		srchResult = _findnext(group, fileInfo);
	}
	cout << "Count: " << count << endl;

	_findclose(group);
	delete fileInfo;
}