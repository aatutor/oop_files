// ����� �. �. 01���2023 ������ ���2221
//������� 1. �� ������ ������ Queue �++ ����������� ������� ������ ��������.
//���������� � ��������� :
//� �� ���� �������� ���������� ���� ��������
//� ��������� ����������� ��������� ������� ����� ��������� �� ������ ��������� �����
//� �������� ������� � ������� ��� ���������� � ��� �����

#include <stdio.h>
#include <iostream>
#include <iomanip>//��� �������
//#include <cstdlib>
#include <cstring>
#include <string>
#include <Windows.h>//��� ��������� ������� ��������

using namespace std;//����� ��������� swap


//��������� ����������� �����
struct Employee {
	string name_;
	string jobTitle_;
	int idEmployee_; //���������
	//����������� �� ���������
	Employee() : name_(""), jobTitle_(""), idEmployee_(0), documentNumber_(0)
	{}
	//�����������, ����������� �������� � main
	Employee(string name, string jobTitle, int idEmployee, int documentNumber) :
		name_(name), jobTitle_(jobTitle), idEmployee_(idEmployee), documentNumber_(documentNumber)
	{}
};
//����� ������� ������ �� �������
class PrintQueue {
private:
	enum { EMPTY = 0, FULL = 10 };
	int wait_[FULL];
	int length_;
	//string* printQueue;


public:
	PrintQueue() {
		length_ = EMPTY;
	};
	void Clear() {
		length_ = EMPTY;
	};
	bool IsEmpty() {
		return length_ == EMPTY;
	};
	bool IsFull() {
		return length_ == FULL;
	};
	int GetCount() {
		return length_;
	}
	//����� ���������� � �������
	void Add(Employee employee) {
		if (IsFull()) {
			cout << "\n ������� ������ �����!" << endl;
			return;
		}
		wait_[length_] = employee.documentNumber_;

		++length_;
		cout << "\n ��������� � �������: " << employee.jobTitle_ << " " << employee.name_ << " ( ����� " << employee.idEmployee_
			<< " ) �������� � " << employee.documentNumber_ << endl;
	}

	//����� ���������� �� ������� 
	int Extract(Employee employee) {
		if (IsEmpty()) {
			cout << " ������� ������ �����! \n";
			return-1;
		}
		int temp = wait_[0];
		for (int i = 0; i < length_ - 1; i++)
			wait_[i] = wait_[i + 1];//��������������
		length_--;//��������� ������ �������
		cout << "\n ����������� �������� ��� " << employee.jobTitle_ << " " << employee.name_ << " � " << temp << "\n";
		return temp;
	}

//������� ������ �������� �������� ������ ������ - �� ����������
	int Extract2(Employee employee) {
		if (IsEmpty()) {
			cout << " ������� ������ �����! \n";
			return -1;
		}
		if (employee.name_ == "�����")
			cout << "!!!";
		int temp = -1;
		for (int i = 0; i < length_; i++) {
			if (wait_[i]  == 10)  // ���� ����� ��������� 10, �� ��� �������� ������
				temp = wait_[i];
			
			for (int j = i; j < length_ - 1; j++) {
				wait_[j] = wait_[j + 1]; // ������������ �������� �������					
			}
			length_--;
			return temp;
			//break;
		}

		if (temp == -1) {
			temp = wait_[0];
			for (int i = 0; i < length_ - 1; i++) {
				wait_[i] = wait_[i + 1]; // ������������ �������� �������
			}
			length_--;
		}
		cout << "\n ����������� �������� ��� " << employee.name_ << " � " << temp << "\n";
		return temp;
	}
	
	void Print() {
		if (IsEmpty())
		{
			cout << " ������� ������ �����! \n";
			return;
		}
		cout << "\n ������� ������ ����������: " << endl;
		for (int i = 0; i < length_; i++) {
			//if (wait_[i] != 0)
				/*{
		cout << "��� ����������: " << employee.name_ << ", � ����������:" << employee.idEmployee_
		<< " � ���������:" */
			cout << wait_[i] << " \n";
		}
	}
	//cout << endl;	
};

struct Doc {
	int empId;
	int docId;
}

class Printer {
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);//��� ��������� ������� ��������
	SetConsoleOutputCP(1251);
	//������ �������
	PrintQueue queue;
	//��������� � ������� ����������� � ��������� ��� ������
	Employee employee1("������","��������", 1);
	Employee employee2("������", "�����", 2, 10);
	Employee employee3("��������", "���������", 3, 15);
	Employee employee4("��������", "��������", 4, 19);



	queue.Add(employee1);
	queue.Add(employee2);
	queue.Add(employee3);
	queue.Add(employee4);

	queue.Print();
	queue.Extract();
	queue.Print();
	queue.Extract(employee2);
	queue.Print();
	queue.Extract(employee3);
	queue.Print();
	queue.Extract(employee4);
	queue.Print();

	PrintQueue::Employee employee5("������", "������", 5, 25);
	queue.Add(employee5);
	queue.Print();
	queue.Extract(employee5);
	queue.Print();

	/*while (!queue.IsEmpty()) {
		int documentNumber = queue.Extract(employee1);
	}*/

	//PrintQueue q;
	//for (int i = 0; i < 8; i++) {
	//	q.Add(rand() % 50);
	//}
	//q.Print();
	//cout << "Get: \n" << q.Extract() << endl;//���������

	//q.Print();
	//cout << "Get: \n" << q.Extract() << endl;//���������	
	//
	//q.Print();
	system("pause");
	return 0;
}


