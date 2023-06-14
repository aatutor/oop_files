#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
using namespace std;

// string ru(const char* str)
// {
// 	char cstr[256];
// 	CharToOemA(str, cstr);
// 	return string{cstr};
// }

int main(int argc, char *argv[])
{

	cout << "Привет" << endl;
	char c;
	cin >> c;
	if (c == 'z')
	// if (strcmp(c, u8"да") == 0)
		cout << "окей" << endl;

	return 0;
}
