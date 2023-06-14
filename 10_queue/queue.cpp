#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	enum {EMPTY = 0, FULL = 10};
	int wait_[FULL];//Очередь
	int length_;	//Текущий размер очереди
public:
	Queue();
	void Clear();	//Очистка очереди
	bool IsEmpty();	//Проверка существования элементов в очереди
	bool IsFull();	//Проверка на переполнение очереди
	int GetCount();	//Количество элементов в очереди

	void Add(int c);//Добавление элемента
	int Extract(); 	//Извлечение элемента
	void Print();	//Печать очереди
};
Queue::Queue()
{
	Clear();
}
void Queue::Clear()
{
	length_ = EMPTY;
}
bool Queue::IsEmpty()
{
	return length_ == EMPTY;
}
bool Queue::IsFull()
{
	return length_ == FULL;
}
int Queue::GetCount()
{
	return length_;
}
void Queue::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if ( !IsFull() )
		wait_[length_++] = c;
}
int Queue::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if ( !IsEmpty() ) {
		//запомнить первый
		int temp = wait_[0];
		//сдвинуть все элементы
		for (int i = 1; i < length_; i++)
			wait_[i - 1] = wait_[i];
		length_--;
		//вернуть первый(нулевой)
		return temp;
	}
	//Если в очереди элементов нет
	return -1;
}
void Queue::Print() {
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < length_; i++) {
		cout << wait_[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}

int main()
{
	srand(time(0));
	//создание очереди
	Queue q;
	//заполнение части элементов
	for (int i = 0; i < 5; i++) 
		q.Add( rand() % 50 );

	//показ очереди
	q.Print();
	//извлечение элемента
	cout << "\nExtracted: " << q.Extract() << endl;
	//показ очереди
	q.Print();
}