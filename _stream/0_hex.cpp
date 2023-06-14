#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;

#define NUM_COLS 18
#define NUM_ROWS 24

int main()
{
	char path[MAX_PATH];
	strcpy(path, "hex.txt");

	int row = 0, i = 0, j = 0;
	char line[NUM_COLS];

	//Открытие файла в двоичном режиме
	ifstream inputFile(path, ios::in | ios::binary);
	if (!inputFile)
	{
		cout << "Cannot open file for display!" << endl;
		return 1;
	}

	//Режим отображения в верхнем регистре для
	//шестнадцатиричного вывода
	cout.setf(ios::uppercase);

	while (!inputFile.eof())
	{
		//Посимвольное чтение
		for (i = 0; (i < NUM_COLS && !inputFile.eof()); i++)
			inputFile.get(line[i]);
		if (i < NUM_COLS)
			i--;
		for (j = 0; j < i; j++)
		{
			cout << " ";
			if ((unsigned)line[j] < 0x10)
				cout << 0;
			cout << (unsigned)line[j];
		}
		//Выравнивание для незавершенной строки
		for (; j < NUM_COLS; j++)
			cout << " ";
		cout << "\t";

		for (j = 0; j < i; j++)
			//Символ не является управляющим?
			if (line[j] > 31 && line[j] <= 255)
				cout << line[j];
			else
				cout << ".";
		cout << "\n";
		//Если экран уже заполнен,
		//производим остановку
		if (++row == NUM_ROWS)
		{
			row = 0;
			cout << "Press any key to continue..." << flush;
			//Ожидаем нажатия любой клавиши
			getch();
			cout << "\n";
		}
	}
	//Закрываем файл
	inputFile.close();

	return 0;
}
