#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

//Функция, выводящая на экран строку
void RussianMessage(const char *str)
{
	char message[100];
	//перевод строки из кодировки Windows (1251)
	CharToOemA(str, message);//в кодировку MS DOS (866)
	cout << message;// .cpp должен быть в кодировке 1251
}
bool CopyFile(char *source, char *destination);

int main()
{
    //MAX_PATH - Константа, определяющая максимальный размер пути.
    //Даная константа содержится в stdlib.h
    char source[_MAX_PATH]{"test.txt"};
    char destination[_MAX_PATH];
    char answer[20];

    if(_access(source,00)==-1){
        RussianMessage("\nУказан неверный путь или название файла\n");
        return 1;
    }
    RussianMessage("\nВведите путь и название нового файла:\n");
    //Получение пути к второму файлу
    cin.getline(destination,_MAX_PATH);
    //Проверка на существование файла
    if(_access(destination,00)==0){
    RussianMessage("\nТакой Файл уже существует перезаписать его(1 - Да /2 - Нет)?\n");
    cin.getline(answer,20);
    if(!strcmp(answer,"2")){
        RussianMessage("\nОперация отменена\n");
        return 2;
    }
    else if(strcmp(answer,"1")){
        RussianMessage("\nНеправильный ввод\n");
        return 3;
    }
    if(_access(destination,02)==-1){
        RussianMessage("\nНет доступа к записи.\n");
        return 4;
    }
    }
    //Копирование файла
    if(!CopyFile(source,destination)){
        RussianMessage("\nОшибка при работе с файлом\n");
    }
    return 0;
}
//Функция копирования файла
bool CopyFile(char *source, char *destination)
{
    const int size = 65536;
    FILE *src, *dest;

    if (!(src = fopen(source, "rb")))
        return false;

    int handle = _fileno(src);  //Получение дескриптора файла
    char *data = new char[size];//выделение памяти под буффер
    if (!data)
        return false;

    //Открытие файла, куда будет производиться копирование
    if (!(dest = fopen(destination, "wb")))
    {
        delete[] data;
        return false;
    }
    int realsize;
    while (!feof(src))
    {
        realsize = fread(data, sizeof(char), size, src);//Чтение данных из файла
        fwrite(data, sizeof(char), realsize, dest);     //Запись данных в файл
    }
    fclose(src);
    fclose(dest);
    return true;
}