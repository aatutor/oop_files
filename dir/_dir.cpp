#include <iostream>
#include <direct.h>
#include <stdio.h>
using namespace std;

void RenameDirectory();
void RemoveDirectory();
void CreateDirectory();

int main()
{
    cout << "Please, select preffer number...\n";
    char ch;
    do {
        cout << "\n1 - Rename\n";
        cout << "2 - Remove\n";
        cout << "3 - Create\n";
        cout << "0 - Exit\n\n";
        cin >> ch;
        switch (ch)
        {
        case '1':
            RenameDirectory();
            break;
        case '2':
            RemoveDirectory();
            break;
        case '3':
            CreateDirectory();
            break;
        }
    } while (ch != '0'); // Выход из программы
}

//Переименовать существующую директорию
void RenameDirectory()
{
    char oldName[50], newName[50];
    //В одной переменной запомним
    //существующее имя (oldName),
    cout << "Enter old name:";
    cin >> oldName;
    //А в другой новое имя(newName)
    cout << "Enter new name:";
    cin >> newName;
    //Произведем переименование и проверку результата
    if (rename(oldName, newName) != 0)
        cout << "Error!\n Couldn't rename directory.\n\n";
    else
        cout << "Ok...\n\n";
}

//Удалить существующую директорию
void RemoveDirectory()
{
    char Name[50];
    //Получаем имя и путь к удаляемой директории
    cout << "Enter name:";
    cin >> Name;
    //Удаляем директорию и проверяем результат
    if (_rmdir(Name) == -1)
        cout << "Error!\n Couldn't remove directory.\n";
    else
        cout << "Ok...\n";
}

//Создать директорию
void CreateDirectory()
{
    char Name[50];
    //Получаем имя и путь к создаваемой директории
    cout << "Enter name:";
    cin >> Name;
    //Создаем директорию и проверяем результат
    if (_mkdir(Name) == -1)
        cout << "Error!\n Couldn't create directory.\n";
    else
        cout << "Ok...\n";
}