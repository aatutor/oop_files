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
	cout << "�ਢ��" << endl;
	char str[50];
	cin >> str;
	if (strcmp(str, "��") == 0)
		cout << "����" << endl;

	return 0;
}
