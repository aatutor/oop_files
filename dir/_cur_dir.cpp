#include <iostream>
#include <direct.h>
#include <stdio.h>
#include <windows.h>
#include <io.h>
using namespace std;

const int size = 255;

//Функция, которая убирает лишние слеши и пробелы справа
void RemoveRSpacesAndRSlashes(char *str)
{
    int index = strlen(str) - 1;
    while (str[index] == '\\' || str[index] == ' ')
    {
        index--;
    }
    strncpy(str, str, index);
    str[index + 1] = '\0';
}
//Функция для показа текущей директории
void ShowCurrentDir(char path[], char temp[])
{
    CharToOemA(path, temp);
    printf("%s>", temp);
}
//Функция перевода из кодировки
//Windows в кодировку DOS
//Для корректного отображения
//кирилицы
void RussianMessage(char path[])
{
    CharToOemA(path, path);
}
//Показ на экран содержимого папки
bool ShowDir(char path[])
{
    //Показ содержимого текущей директории
    _finddata_t find;
    char pathfind[MAX_PATH];
    strcpy(pathfind, path);
    strcat(pathfind, "\\*.*");
    char info[MAX_PATH];
    //Начало Поиска
    int result = _findfirst(pathfind, &find);
    //Очистка экрана
    system("cls");
    int flag = result;
    if (flag == -1)
    {
        strcpy(info, "Такой Директории Нет");
        RussianMessage(info);
        printf("%s\n", info);
        return false;
    }
    while (flag != -1)
    {
        if (strcmp(find.name, ".") && strcmp(find.name, ".."))
        {
            //Проверяем Директория или Нет
            find.attrib &_A_SUBDIR ? strcpy(info, " Каталог ") : strcpy(info, " Файл ");
            RussianMessage(info);
            RussianMessage(find.name);
            printf("%30s %10s\n", find.name, info);
        }
        //Продолжаем Поиск
        flag = _findnext(result, &find);
    }
    ShowCurrentDir(path, info);
    //Очищаем ресурсы, выделенные под поиск
    _findclose(result);
    return true;
}
int main()
{
    //В данной переменной будет храниться
    //путь к Директории
    char path[MAX_PATH];
    //В данной переменной будет команда, введенная
    //пользователем
    char action[size];
    //Временная переменная
    char temp[MAX_PATH];
    //Получаем Путь к текущей Директории
    GetCurrentDirectory(sizeof(path), path);
    bool flag = true;
    //Показ содержимого текущей директории
    ShowDir(path);
    do
    {
        //Ввод команды пользователя
        cin.getline(action, size);
        //Убираем пробелы и слэши справа
        RemoveRSpacesAndRSlashes(action);
        //Переход в корневой каталог
        if (!strcmpi(action, "root"))
        {
            path[2] = '\0';
            ShowDir(path);
        }
        //Проверка на желание пользователя выйти
        else if (!strcmpi(action, "exit"))
        {
            flag = false;
        }
        //Проверка на команду cd
        else if (!strnicmp(action, "cd", 2))
        {
            //Показ содержимого текущей директории
            if ((!strcmpi(action, "cd")))
            {
                //Показ Директории
                ShowDir(path);
            }
            //Команда cd была дана с параметрами
            else if (!strnicmp(action, "cd ", 3))
            {
                //Находим индекс параметра
                int index = strspn(action + 2, " ");
                if (index)
                {
                    //Проверка на полный путь к Директории
                    if (strchr(action + index + 2, ':'))
                    {
                        //Попытка отобразить содержимое
                        //Директории
                        if (ShowDir(action + index + 2))
                        {
                            strcpy(path, action + index + 2);
                        }
                        else
                        {
                            //Произошла Ошибка
                            ShowCurrentDir(path, temp);
                        }
                    }
                    //Поднимаемся в родительский каталог
                    else if (!strcmp(action + index + 2, ".."))
                    {
                        char *result = strrchr(path, '\\');
                        if (result)
                        {
                            int delta = result - path;
                            strncpy(temp, path, delta);
                            temp[delta] = '\0';
                        }
                        else
                        {
                            strcpy(temp, path);
                        }
                        if (ShowDir(temp))
                        {
                            strcpy(path, temp);
                        }
                        else
                        {
                            //Произошла Ошибка
                            ShowCurrentDir(path, temp);
                        }
                    }
                    //Показ Директории
                    else if (!strcmp(action + index + 2, "."))
                    {
                        ShowDir(path);
                    }
                    else if (!strcmp(action + index + 2, "/"))
                    {
                        ShowDir(path);
                    }
                    else
                    {
                        //Был Дан неполный путь
                        strcpy(temp, path);
                        strcat(temp, "\\");
                        strcat(temp, action + index + 2);
                        //Попытка отобразить содержимое
                        //Директории
                        if (ShowDir(temp))
                        {
                            strcpy(path, temp);
                        }
                        else
                        {
                            //Произошла Ошибка
                            ShowCurrentDir(path, temp);
                        }
                    }
                }
                else
                {
                    //Показ Директории
                    ShowDir(path);
                }
            }
            else
            {
                //Показ Директории
                ShowDir(path);
            }
        }
        else
        {
            //Показ Директории
            ShowDir(path);
        }
    } while (flag);
}