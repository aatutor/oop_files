#include <iostream>
#include <direct.h>
#include <stdio.h>
using namespace std;

void renameDirectory(const char*, const char*);
void removeDirectory(const char*);
void createDirectory(const char*);
void showDirectories();

int main()
{
    const char* fstName {"my_folder"};
    const char* scndName {"renamed_folder"};

    createDirectory(fstName);
    showDirectories();

    renameDirectory(fstName, scndName);
    showDirectories();

    removeDirectory(scndName);
    showDirectories();

    return 0;
}

//������������� ������������ ����������
void renameDirectory(const char* oldName, const char* newName)
{
    //���������� �������������� � �������� ����������
    if (rename(oldName, newName) != 0)
        cout << "Error!\n Couldn't rename directory.\n\n";
    else
        cout << "OK: " 
            << oldName << " renamed to "
            << newName << "\n\n";
}
//������� ������������ ����������
void removeDirectory(const char* name)
{
    //������� ���������� � ��������� ���������
    if (_rmdir(name) == -1)
        cout << "Error!\n Couldn't remove directory.\n";
    else
        cout << "OK: " 
            << name << " was removed\n\n";
}
//������� ����������
void createDirectory(const char* name)
{
    //������� ���������� � ��������� ���������
    if (_mkdir(name) == -1)
        cout << "Error!\n Couldn't create directory.\n";
    else
        cout << "OK: " 
            << name << " was created\n\n";
}
// ������� ������ ���������� ������ �������
void showDirectories()
{
    _finddata_t fileInfo;
    intptr_t group = _findfirst("*", &fileInfo);

    int srchResult = group;
    cout << "Directory list:\n";
	while (srchResult != -1) {
		if (fileInfo.attrib == _A_SUBDIR)
    		cout << "\t/" << fileInfo.name << endl;
		srchResult = _findnext(group, &fileInfo);
	}
    cout << endl;

	_findclose(group);
}