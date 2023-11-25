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

	//�������� ����� � �������� ������
	ifstream inputFile(path, ios::in | ios::binary);
	if (!inputFile)
	{
		cout << "Cannot open file for display!" << endl;
		return 1;
	}

	//����� ����������� � ������� �������� ���
	//������������������ ������
	cout.setf(ios::uppercase);

	while (!inputFile.eof())
	{
		//������������ ������
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
		//������������ ��� ������������� ������
		for (; j < NUM_COLS; j++)
			cout << " ";
		cout << "\t";

		for (j = 0; j < i; j++)
			//������ �� �������� �����������?
			if (line[j] > 31 && line[j] <= 255)
				cout << line[j];
			else
				cout << ".";
		cout << "\n";
		//���� ����� ��� ��������,
		//���������� ���������
		if (++row == NUM_ROWS)
		{
			row = 0;
			cout << "Press any key to continue..." << flush;
			//������� ������� ����� �������
			getch();
			cout << "\n";
		}
	}
	//��������� ����
	inputFile.close();

	return 0;
}
