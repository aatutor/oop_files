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

	////Задаем по умолчанию черный цвет
	//char color[8] = "#000000";
	////формируем начало HTML - документа
	//char htmlDOM[256] = "<html><head><title> New file !!!</title></head> <body bgcolor = \'";
	////Открываем файл на запись с созданием
	//FILE *htmlFile = fopen("D:\\1.html", "w+");
	////Если не получилось - останавливаемся
	//if (!htmlFile)
	//	return 1;
	////Если параметр цвета передан - используем его
	//if (argc == 2)
	//	strcpy(color, argv[1]);

	////Присоединяем цвет к документу
	//strcat(htmlDOM, color);
	////Присоединяем окончание к документу
	//strcat(htmlDOM, "\'></body></html>");
	////Сохраняем в файл
	//fputs(htmlDOM, htmlFile);
	////Закрываем Файл
	//fclose(htmlFile);
	//cout << "\nOK.....\n";
}
