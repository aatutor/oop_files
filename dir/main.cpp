#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

char* ru(char *str)
{
	char *rus = new char[256];
	CharToOemA(str, rus);
	return rus;
}

int main(int argc, char *argv[])
{
	cout << "> count: " << argc << endl;
	for (int i = 0; i < argc; i++)
		cout << ru(argv[i]) << endl;

	////������ �� ��������� ������ ����
	//char color[8] = "#000000";
	////��������� ������ HTML - ���������
	//char htmlDOM[256] = "<html><head><title> New file !!!</title></head> <body bgcolor = \'";
	////��������� ���� �� ������ � ���������
	//FILE *htmlFile = fopen("D:\\1.html", "w+");
	////���� �� ���������� - ���������������
	//if (!htmlFile)
	//	return 1;
	////���� �������� ����� ������� - ���������� ���
	//if (argc == 2)
	//	strcpy(color, argv[1]);

	////������������ ���� � ���������
	//strcat(htmlDOM, color);
	////������������ ��������� � ���������
	//strcat(htmlDOM, "\'></body></html>");
	////��������� � ����
	//fputs(htmlDOM, htmlFile);
	////��������� ����
	//fclose(htmlFile);
	//cout << "\nOK.....\n";
}
