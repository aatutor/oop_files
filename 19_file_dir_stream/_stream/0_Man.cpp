#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

void RussianMessage(const char *message)
{
	char ruMessage[256];
	CharToOem(message, ruMessage);
	cout << ruMessage;
}
int RussianMenu()
{
	RussianMessage("\nВведите 1 для добавления новой структуры в файл\n");
	RussianMessage("Введите 2 для показа всех структур из файла\n");
	RussianMessage("Введите 3 для выхода\n");
	int choice;
	cin >> choice;
	return choice;
}
class Man
{
	//переменная для возраста
	int age;
	//переменная для имени
	char *name;
	//переменная для фамилии
	char *surname;

public:
	//конструктор с параметрами
	Man(char *n, char *s, int a);
	//конструктор
	Man();
	//деструктор
	~Man();

public:
	//функция ввода данных
	void Put();
	//функция показа данных
	void Show();
	//функция сохранения в файл
	void SaveToFile();
	//функция показа содержимого файла
	static void ShowFromFile();
};
//конструктор

int main()
{
	Man *a;
	//Основной цикл программы
	do
	{
		switch (RussianMenu())
		{
		case 1: //Добавление записи
			a = new Man;
			a->Put();
			a->SaveToFile();
			delete a;
			break;
		case 2: //Показ всех записей
			Man::ShowFromFile();
			break;
		case 3: //Прощание с пользователем
			RussianMessage("До Свидания\n");
			return 0;
		default: //Неправильный ввод
			RussianMessage("Неверный Ввод\n");
		}
	} while (1);
}

Man::Man()
{
	name = 0;
	surname = 0;
	age = 0;
}
//конструктор с параметрами
Man::Man(char *n, char *s, int a)
{
	name = new char[strlen(n) + 1];
	if (!name)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy(name, n);
	surname = new char[strlen(s) + 1];
	if (!surname)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(2);
	}
	strcpy(surname, s);
	age = a;
}
//деструктор
Man::~Man()
{
	delete[] name;
	delete[] surname;
}
//функция ввода данных
void Man::Put()
{
	char temp[1024];
	RussianMessage("\nВведите имя:\n");
	cin >> temp;
	if (name)
		delete[] name;
	name = new char[strlen(temp) + 1];
	if (!name)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy(name, temp);
	RussianMessage("\nВведите фамилию:\n");
	cin >> temp;
	if (surname)
		delete[] surname;
	surname = new char[strlen(temp) + 1];
	if (!surname)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy(surname, temp);
	RussianMessage("\nВведите возраст\n");
	cin >> age;
}
//функция показа данных
void Man::Show()
{
	RussianMessage("\nИмя:\n");
	cout << name;
	RussianMessage("\nФамилия:\n");
	cout << surname;
	RussianMessage("\nВозраст:\n");
	cout << age << "\n";
}
//функция сохранения в файл
void Man::SaveToFile()
{
	int size;
	fstream f("men.txt", ios::out | ios::binary | ios::app);
	if (!f)
	{
		RussianMessage("Файл не открылся для записи !!!");
		exit(1);
	}
	//Записываем возраст
	f.write((char *)&age, sizeof(age));
	size = strlen(name);
	//Записываем количество символов в имени
	f.write((char *)&size, sizeof(int));
	//Записываем имя
	f.write((char *)name, size * sizeof(char));
	size = strlen(surname);
	//Записываем количество символов в фамилии
	f.write((char *)&size, sizeof(int));
	//Записываем фамилию
	f.write((char *)surname, size * sizeof(char));
	f.close();
}
//функция показа содержимого файла
void Man::ShowFromFile()
{
	fstream f("men.txt", ios::in | ios::binary);
	if (!f)
	{
		RussianMessage("Файл не открылся для чтения !!!");
		exit(3);
	}
	char *n, *s;
	int a;
	int temp;
	//В цикле зачитываем содержимое файла
	while (f.read((char *)&a, sizeof(int)))
	{
		RussianMessage("\nИмя:\n");
		f.read((char *)&temp, sizeof(int));
		n = new char[temp + 1];
		if (!n)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(4);
		}
		f.read((char *)n, temp * sizeof(char));
		n[temp] = '\0';
		cout << n;
		RussianMessage("\nФамилия:\n");
		f.read((char *)&temp, sizeof(int));
		s = new char[temp + 1];
		if (!s)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(5);
		}
		f.read((char *)s, temp * sizeof(char));
		s[temp] = '\0';
		cout << s;
		RussianMessage("\nВозраст:\n");
		cout << a << "\n";
		delete[] n;
		delete[] s;
	}
}