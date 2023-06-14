#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
//#include <stdio.h>
#include <windows.h>
#include <io.h>
using namespace std;

char* ru(const char *str)
{
	char *rus = new char[256];
	CharToOemA(str, rus);
	return rus;
}

void removeRSpacesAndRSlashes(char *str)
{
	int index = strlen(str) - 1;
	while (str[index] == '\\' || str[index] == ' ')
		index--;

	strncpy(str, str, index);
	str[index + 1] = '\0';
}

bool isDir(const char* path)
{
	_finddata_t find;
	int group = _findfirst(path, &find);
	_findclose(group);

	return find.attrib == _A_SUBDIR;
}

void showListOn(char path[])
{
	if (!isDir(path)) {
		cout << ru("Такой Директории Нет") << endl;
		return;
	}
	//Показ содержимого текущей директории
	_finddata_t find;
	char pathfind[MAX_PATH];
	strcpy(pathfind, path);
	strcat(pathfind, "\\*.*");

	int group = _findfirst(pathfind, &find);
	int result = group;
	while (result != -1)
	{
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
			cout << ru(find.attrib == _A_SUBDIR
				? " Каталог: " : " Файл: ")
			<< ru(find.name) << endl;

		result = _findnext(group, &find);
	}

	_findclose(group);
}

bool cd(char* path, char* command)
{
	char temp[MAX_PATH];

	int countSpaces = strspn(command + 2, " ");
	strcpy(command, command + countSpaces + 2);

	if (!strcmp(command, ".") || !strcmp(command, "/"))
	{
		return true;
	}
	else if (strchr(command, ':'))
	{
		if (!isDir(command))
			return false;
		strcpy(path, command);
		return true;
	}
	else if (!strcmp(command, ".."))
	{
		char *lastSlash = strrchr(path, '\\');
		if (lastSlash)
		{
			int delta = lastSlash - path;
			strncpy(temp, path, delta);
			temp[delta] = '\0';
		}
		else
			strcpy(temp, path);

		//if (!isDir(temp))
		//	return false;
	}
	else // указан неполный путь
	{
		strcpy(temp, path);
		strcat(temp, "\\");
		strcat(temp, command);

		if (!isDir(temp))
			return false;
	}
	strcpy(path, temp);
	return true;
}

int main()
{
	const int SIZE = 255;

	char path[MAX_PATH];
	char command[SIZE];

	GetCurrentDirectoryA(sizeof(path), path);
	showListOn(path);

	bool repeat = true;
	while (repeat)
	{
		cout << ru(path) << ">";

		cin.getline(command, SIZE);

		system("cls");

		removeRSpacesAndRSlashes(command);
		if (!_strcmpi(command, "root"))
			path[2] = '\0';

		else if (!_strcmpi(command, "exit")) {
			repeat = false;
			continue;
		}
		//Команда cd была дана с параметрами
		else if (!_strnicmp(command, "cd ", 3))
			if (!cd(path, command)) {
				cout << ru("Неверный путь") << endl;
				continue;
			}

		showListOn(path);
	}
}
