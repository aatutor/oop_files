// Ильин В. В. 01Мая2023 Группа ВБД2221
//Задание 1. На основе класса Queue С++ сымитируйте очередь печати принтера.
//Реализуйте в программе :
//• за одну итерацию печатается один документ
//• несколько сотрудников случайным образом могут отправить на печать случайное число
//• «Принтер» выводит в консоль имя сотрудника и его число

#include <stdio.h>
#include <iostream>
#include <iomanip>//для отступа
//#include <cstdlib>
#include <cstring>
#include <string>
#include <Windows.h>//для понимания русских символов

using namespace std;//здесь находится swap


//Класс Очередь печати на принтер
class PrintQueue {
private:
	enum { EMPTY = 0, FULL = 10 };
	int wait_[FULL];
	int length_;
	//string* printQueue;

//Структура сотрудников офиса
public: struct Employee {
	string name_;
	string jobTitle_;
	int idEmployee_; //Сотрудник
	int documentNumber_;//Номер документа для печати
	//конструктор по умолчанию
	Employee() : name_(""), jobTitle_(""), idEmployee_(0), documentNumber_(0)
	{}
	//конструктор, принимающий значения в main
	Employee(string name, string jobTitle, int idEmployee, int documentNumber) :
		name_(name), jobTitle_(jobTitle), idEmployee_(idEmployee), documentNumber_(documentNumber)
	{}
};

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
	//метод добавления в очередь
	void Add(Employee employee) {
		if (IsFull()) {
			cout << "\n Очередь печати полна!" << endl;
			return;
		}
		wait_[length_] = employee.documentNumber_;

		++length_;
		cout << "\n Добавляем в очередь: " << employee.jobTitle_ << " " << employee.name_ << " ( номер " << employee.idEmployee_
			<< " ) документ № " << employee.documentNumber_ << endl;
	}

	//метод извлечения из очереди 
	int Extract(Employee employee) {
		if (IsEmpty()) {
			cout << " Очередь печати пуста! \n";
			return-1;
		}
		int temp = wait_[0];
		for (int i = 0; i < length_ - 1; i++)
			wait_[i] = wait_[i + 1];//перекопировали
		length_--;//уменьшили размер массива
		cout << "\n Распечатали документ для " << employee.jobTitle_ << " " << employee.name_ << " № " << temp << "\n";
		return temp;
	}

//попытка метода печатать документ юриста первым - не получилось
	int Extract2(Employee employee) {
		if (IsEmpty()) {
			cout << " Очередь печати пуста! \n";
			return -1;
		}
		if (employee.name_ == "Юрист")
			cout << "!!!";
		int temp = -1;
		for (int i = 0; i < length_; i++) {
			if (wait_[i]  == 10)  // если номер документа 10, то это документ юриста
				temp = wait_[i];
			
			for (int j = i; j < length_ - 1; j++) {
				wait_[j] = wait_[j + 1]; // перекопируем элементы массива					
			}
			length_--;
			return temp;
			//break;
		}

		if (temp == -1) {
			temp = wait_[0];
			for (int i = 0; i < length_ - 1; i++) {
				wait_[i] = wait_[i + 1]; // перекопируем элементы массива
			}
			length_--;
		}
		cout << "\n Распечатали документ для " << employee.name_ << " № " << temp << "\n";
		return temp;
	}
	
	void Print() {
		if (IsEmpty())
		{
			cout << " Очередь печати пуста! \n";
			return;
		}
		cout << "\n Очередь печати документов: " << endl;
		for (int i = 0; i < length_; i++) {
			//if (wait_[i] != 0)
				/*{
		cout << "Имя сотрудника: " << employee.name_ << ", № сотрудника:" << employee.idEmployee_
		<< " № документа:" */
			cout << wait_[i] << " \n";
		}
	}
	//cout << endl;	
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);//для понимания русских символов
	SetConsoleOutputCP(1251);
	//Создаём очередь
	PrintQueue queue;
	//Добавляем в очередь сотрудников и документы для печати
	PrintQueue::Employee employee1("Иванов","Менеджер", 1, 3);
	PrintQueue::Employee employee2("Петров", "Юрист", 2, 10);
	PrintQueue::Employee employee3("Сидорова", "Секретарь", 3, 15);
	PrintQueue::Employee employee4("Васечкин", "Директор", 4, 19);
	queue.Add(employee1);
	queue.Add(employee2);
	queue.Add(employee3);
	queue.Add(employee4);

	queue.Print();
	queue.Extract(employee1);
	queue.Print();
	queue.Extract(employee2);
	queue.Print();
	queue.Extract(employee3);
	queue.Print();
	queue.Extract(employee4);
	queue.Print();

	PrintQueue::Employee employee5("Эдисон", "Курьер", 5, 25);
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
	//cout << "Get: \n" << q.Extract() << endl;//извлекаем

	//q.Print();
	//cout << "Get: \n" << q.Extract() << endl;//извлекаем	
	//
	//q.Print();
	system("pause");
	return 0;
}


