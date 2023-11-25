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
	RussianMessage("\n������� 1 ��� ���������� ����� ��������� � ����\n");
	RussianMessage("������� 2 ��� ������ ���� �������� �� �����\n");
	RussianMessage("������� 3 ��� ������\n");
	int choice;
	cin >> choice;
	return choice;
}
class Man
{
	//���������� ��� ��������
	int age;
	//���������� ��� �����
	char *name;
	//���������� ��� �������
	char *surname;

public:
	//����������� � �����������
	Man(char *n, char *s, int a);
	//�����������
	Man();
	//����������
	~Man();

public:
	//������� ����� ������
	void Put();
	//������� ������ ������
	void Show();
	//������� ���������� � ����
	void SaveToFile();
	//������� ������ ����������� �����
	static void ShowFromFile();
};
//�����������

int main()
{
	Man *a;
	//�������� ���� ���������
	do
	{
		switch (RussianMenu())
		{
		case 1: //���������� ������
			a = new Man;
			a->Put();
			a->SaveToFile();
			delete a;
			break;
		case 2: //����� ���� �������
			Man::ShowFromFile();
			break;
		case 3: //�������� � �������������
			RussianMessage("�� ��������\n");
			return 0;
		default: //������������ ����
			RussianMessage("�������� ����\n");
		}
	} while (1);
}

Man::Man()
{
	name = 0;
	surname = 0;
	age = 0;
}
//����������� � �����������
Man::Man(char *n, char *s, int a)
{
	name = new char[strlen(n) + 1];
	if (!name)
	{
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(1);
	}
	strcpy(name, n);
	surname = new char[strlen(s) + 1];
	if (!surname)
	{
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(2);
	}
	strcpy(surname, s);
	age = a;
}
//����������
Man::~Man()
{
	delete[] name;
	delete[] surname;
}
//������� ����� ������
void Man::Put()
{
	char temp[1024];
	RussianMessage("\n������� ���:\n");
	cin >> temp;
	if (name)
		delete[] name;
	name = new char[strlen(temp) + 1];
	if (!name)
	{
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(1);
	}
	strcpy(name, temp);
	RussianMessage("\n������� �������:\n");
	cin >> temp;
	if (surname)
		delete[] surname;
	surname = new char[strlen(temp) + 1];
	if (!surname)
	{
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(1);
	}
	strcpy(surname, temp);
	RussianMessage("\n������� �������\n");
	cin >> age;
}
//������� ������ ������
void Man::Show()
{
	RussianMessage("\n���:\n");
	cout << name;
	RussianMessage("\n�������:\n");
	cout << surname;
	RussianMessage("\n�������:\n");
	cout << age << "\n";
}
//������� ���������� � ����
void Man::SaveToFile()
{
	int size;
	fstream f("men.txt", ios::out | ios::binary | ios::app);
	if (!f)
	{
		RussianMessage("���� �� �������� ��� ������ !!!");
		exit(1);
	}
	//���������� �������
	f.write((char *)&age, sizeof(age));
	size = strlen(name);
	//���������� ���������� �������� � �����
	f.write((char *)&size, sizeof(int));
	//���������� ���
	f.write((char *)name, size * sizeof(char));
	size = strlen(surname);
	//���������� ���������� �������� � �������
	f.write((char *)&size, sizeof(int));
	//���������� �������
	f.write((char *)surname, size * sizeof(char));
	f.close();
}
//������� ������ ����������� �����
void Man::ShowFromFile()
{
	fstream f("men.txt", ios::in | ios::binary);
	if (!f)
	{
		RussianMessage("���� �� �������� ��� ������ !!!");
		exit(3);
	}
	char *n, *s;
	int a;
	int temp;
	//� ����� ���������� ���������� �����
	while (f.read((char *)&a, sizeof(int)))
	{
		RussianMessage("\n���:\n");
		f.read((char *)&temp, sizeof(int));
		n = new char[temp + 1];
		if (!n)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(4);
		}
		f.read((char *)n, temp * sizeof(char));
		n[temp] = '\0';
		cout << n;
		RussianMessage("\n�������:\n");
		f.read((char *)&temp, sizeof(int));
		s = new char[temp + 1];
		if (!s)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(5);
		}
		f.read((char *)s, temp * sizeof(char));
		s[temp] = '\0';
		cout << s;
		RussianMessage("\n�������:\n");
		cout << a << "\n";
		delete[] n;
		delete[] s;
	}
}