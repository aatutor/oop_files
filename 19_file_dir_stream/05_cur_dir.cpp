/*
	cd "Путь" 	— переход в другую директорию
	cd .. 		— показ содержимого родительского каталога и переход
	cd . или cd	— показ содержимого текущего каталога
	exit 		— выход из программы
	root 		— переход в корневой каталог
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
#include <windows.h>
#include <io.h>
using namespace std;

#if 0
//Функция, выводящая на экран строку
void RussianMessage(char *str){
	char message[100];
	//перевод строки из кодировки Windows
	//в кодировку MS DOS
	CharToOemA(str, message); 	// .cpp должен быть в кодировке 1251
	cout<<message;          	// а консоль - в 866
}
char* ru(const char *str)
{
	char *rus = new char[strlen(str)]; 
	CharToOemA(str, rus);
	return rus; // плохой косяк!
}
void Test()
{
	cout << ru("привет мир") << endl;
	RussianMessage("хороший день");
}
#else
ostream& operator << (ostream& out, const char* str){
	char rus[256];
	CharToOemA(str, rus);
	// out << rus;
	// out << string{rus};
	std::operator<<(out, rus);
	return out;
}
#endif
// cout << "нормальный русский" << endl;

/// TODO: add cin >> rus

/// TODO: починить абс. путь и корень
void RemoveRSpacesAndRSlashes(char *str)
{
	int index = strlen(str) - 1;
	while (str[index] == '\\' || str[index] == ' ')
		index--;

	str[index + 1] = '\0';
}

bool IsDir(const char* path)
{
	_finddata_t find;

	int group = _findfirst(path, &find);
	_findclose(group);

	return (group != -1) && (find.attrib & _A_SUBDIR) != 0;
}

//Показ содержимого текущей директории
void ShowDirList(const char path[])
{
	if ( IsDir(path) == 0 ) {
		cout << "Такой Директории Нет" << endl;
		return;
	}
	_finddata_t find;

	string pathDir {path};
	// pathDir.append("\\*");
	pathDir += "\\*";
	intptr_t group = _findfirst(pathDir.c_str(), &find);

	// intptr_t group = _findfirst(
	// 		string{path}.append("\\*").c_str(), &find); // вариант без переменной

	if (group == -1)
		return; // почему не вызываем _findclose?

	do {
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
		{
			cout << ((find.attrib & _A_SUBDIR) != 0 ? 
					" Каталог: " : " Файл: ")
					<< find.name << endl;
		}
	} while (_findnext(group, &find) != -1);

	_findclose(group);
}

bool cd(char* path, char* command)
{
/// TODO: use string
	char temp[MAX_PATH];

	int countSpaces = strspn(command + 2, " ");
	strcpy(command, command + countSpaces + 2);

	if ( !strcmp(command, ".") || !strcmp(command, "/") )
	{	// не нужно менять директорию
		return true;
	}
	if ( strchr(command, ':') )
	{	// введен абсолютный путь
		if ( !IsDir(command) )
			return false;
		strcpy(path, command);
		return true;
	}
	if ( !strcmp(command, "..") )
	{	// перейти на каталог выше
		char *lastSlash = strrchr(path, '\\');
		if (lastSlash)
		{
			int delta = lastSlash - path;
			strncpy(temp, path, delta);
			temp[delta] = '\0';
		}
		else
			strcpy(temp, path);
// TODO: проверить актуальность:
		//if (!IsDir(temp))
		//	return false;
	}
	else 
	{	// указан неполный путь
		strcpy(temp, path);
		strcat(temp, "\\");
		strcat(temp, command);

		if (!IsDir(temp))
			return false;
	}
	strcpy(path, temp);	// поменять путь
	return true;
}

void Explorer()
{
	const int SIZE = 255;

	char path[MAX_PATH];
	char command[SIZE];

	GetCurrentDirectoryA(sizeof(path), path);
	ShowDirList(path);

	while (true)
	{
		cout << path << ">";

		cin.getline(command, SIZE);
		RemoveRSpacesAndRSlashes(command);

		system("cls");

		if ( !_strcmpi(command, "root") ){
			path[2] = '\0';
		}
		else if ( !_strcmpi(command, "exit") ) {
			break;
		}
		//Команда cd была дана с параметрами
		else if ( !_strnicmp(command, "cd ", 3) ){
			if ( !cd(path, command) ) {
				cout << "Неверный путь" << endl;
				continue;
			}
		}
		ShowDirList(path);
	}
}

int main()
{
	Explorer();
}
