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
	//���������
	enum
	{
		CHOICE = 3,
		INPUT_FILENAME,
		INPUT_DIMENSIONS,
		INPUT_ELEMENTS,
		FILE_ERROR
	};
	//���������
	char msg[MSG_CNT][50] =
		{
			"1. ������� ������ �� ���������� �����\n",
			"2. �������� ������ � ��������� ����\n",
			"3. ����� �� ���������\n",
			"\n��� �����: ",
			"������� ��� ��������������� �����: ",
			"������� ����������� �������:\n",
			"������� �������� �������:\n",
			"���������� ������� ����\n"};
	//����������� ��������� � ����� ���� �� �����
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
	//���������� ��� ����� �����
	char FileName[MAX_PATH];
	//����������� �������
	int m, n;
	int num;

	cout << "\n" << msg[INPUT_FILENAME];
	cin >> FileName;
	//���� ������ ������ ����� ����,
	//�� ������� ������ �� ���������� ����� �� �����
	if (answer == '1')
	{
		//���� ���� � ��������� ������ �� ����������,
		//������� ��������� �� ������
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << endl
				 << msg[FILE_ERROR];
			return;
		}
		//��������� ����������� �������
		inF >> M;
		inF >> N;
		//��������� �������� ������� �� ����� �
		//������� �� ����� �� �����
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
	//���� ������ ������ ����� ����, �� �����������
	//� ������������ ������ � ������� �� � ���������
	//����
	else
	{
		//��������� ���� ��� ������.
		//���� ���� � ��������� ������ �� ����������,
		//�� ��������� ������� ���
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n"
				 << msg[FILE_ERROR];
			return;
		}
		//����������� ����������� �������
		//� ���������� ������ � ����
		cout << msg[INPUT_DIMENSIONS];
		cout << "M: ";
		cin >> M;
		cout << "N: ";
		cin >> N;
		outF << M << ' ' << N << "\n";
		cout << msg[INPUT_ELEMENTS];
		//����������� �������� ������� � ����������
		//�� � ����
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