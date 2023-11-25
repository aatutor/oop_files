/*
	cd "����" 	� ������� � ������ ����������
	cd .. 		� ����� ����������� ������������� �������� � �������
	cd . ��� cd	� ����� ����������� �������� ��������
	exit 		� ����� �� ���������
	root 		� ������� � �������� �������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
#include <windows.h>
#include <io.h>
using namespace std;

#if 0
//�������, ��������� �� ����� ������
void RussianMessage(char *str){
	char message[100];
	//������� ������ �� ��������� Windows
	//� ��������� MS DOS
	CharToOemA(str, message); 	// .cpp ������ ���� � ��������� 1251
	cout<<message;          	// � ������� - � 866
}
char* ru(const char *str)
{
	char *rus = new char[strlen(str)]; 
	CharToOemA(str, rus);
	return rus; // ������ �����!
}
void Test()
{
	cout << ru("������ ���") << endl;
	RussianMessage("������� ����");
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
// cout << "���������� �������" << endl;

/// TODO: add cin >> rus

/// TODO: �������� ���. ���� � ������
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

//����� ����������� ������� ����������
void ShowDirList(const char path[])
{
	if ( IsDir(path) == 0 ) {
		cout << "����� ���������� ���" << endl;
		return;
	}
	_finddata_t find;

	string pathDir {path};
	// pathDir.append("\\*");
	pathDir += "\\*";
	intptr_t group = _findfirst(pathDir.c_str(), &find);

	// intptr_t group = _findfirst(
	// 		string{path}.append("\\*").c_str(), &find); // ������� ��� ����������

	if (group == -1)
		return; // ������ �� �������� _findclose?

	do {
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
		{
			cout << ((find.attrib & _A_SUBDIR) != 0 ? 
					" �������: " : " ����: ")
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
	{	// �� ����� ������ ����������
		return true;
	}
	if ( strchr(command, ':') )
	{	// ������ ���������� ����
		if ( !IsDir(command) )
			return false;
		strcpy(path, command);
		return true;
	}
	if ( !strcmp(command, "..") )
	{	// ������� �� ������� ����
		char *lastSlash = strrchr(path, '\\');
		if (lastSlash)
		{
			int delta = lastSlash - path;
			strncpy(temp, path, delta);
			temp[delta] = '\0';
		}
		else
			strcpy(temp, path);
// TODO: ��������� ������������:
		//if (!IsDir(temp))
		//	return false;
	}
	else 
	{	// ������ �������� ����
		strcpy(temp, path);
		strcat(temp, "\\");
		strcat(temp, command);

		if (!IsDir(temp))
			return false;
	}
	strcpy(path, temp);	// �������� ����
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
		//������� cd ���� ���� � �����������
		else if ( !_strnicmp(command, "cd ", 3) ){
			if ( !cd(path, command) ) {
				cout << "�������� ����" << endl;
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
