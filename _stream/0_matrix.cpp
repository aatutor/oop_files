#include <windows.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#define MSG_CNT = 8;

int main()
{
	char answer;
	int i, j;
	//Подсказки
	enum
	{
		CHOICE = 3,
		INPUT_FILENAME,
		INPUT_DIMENSIONS,
		INPUT_ELEMENTS,
		FILE_ERROR
	};
	//Сообщения
	char msg[MSG_CNT][50] =
		{
			"1. Вывести данные из текстового файла\n",
			"2. Записать данные в текстовый файл\n",
			"3. Выход из программы\n",
			"\nВаш выбор: ",
			"Введите имя обрабатываемого файла: ",
			"Введите размерности матрицы:\n",
			"Введите элементы матрицы:\n",
			"Невозможно открыть файл\n"};
	//Русификация сообщений и вывод меню на экран
	for (i = 0; i < MSG_CNT; i++)
		CharToOem(msg[i], msg[i]);
	do
	{
		system("cls");
		for (int i = 0; i < 4; i++)
			cout << msg[i];
		cin >> answer;
	} while (answer < '1' || answer > '3');
	if (answer == '3')
		return 0;
	//Переменная для имени файла
	char FileName[MAX_PATH];
	//Размерности матрицы
	int m, n;
	int num;

	cout << "\n" << msg[INPUT_FILENAME];
	cin >> FileName;
	//Если выбран первый пункт меню,
	//то выводим данные из текстового файла на экран
	if (answer == '1')
	{
		//Если файл с указанным именем не существует,
		//выводим сообщение об ошибке
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << endl
				 << msg[FILE_ERROR];
			return;
		}
		//Считываем размерность массива
		inF >> M;
		inF >> N;
		//Считываем элементы массива из файла и
		//выводим их сразу на экран
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << endl;
		}
		inF.close();
	}
	//Если выбран второй пункт меню, то запрашиваем
	//у пользователя данные и выводим их в текстовый
	//файл
	else
	{
		//Открываем файл для записи.
		//Если файл с указанным именем не существует,
		//то программа создает его
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n"
				 << msg[FILE_ERROR];
			return;
		}
		//Запрашиваем размерность матрицы
		//и записываем данные в файл
		cout << msg[INPUT_DIMENSIONS];
		cout << "M: ";
		cin >> M;
		cout << "N: ";
		cin >> N;
		outF << M << ' ' << N << "\n";
		cout << msg[INPUT_ELEMENTS];
		//Запрашиваем элементы массива и записываем
		//их в файл
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << "A[" << i << "][" << j << "] = ";
				cin >> num;
				outF << num << " ";
			}
			outF << "\n";
		}
		outF.close();
	}
}