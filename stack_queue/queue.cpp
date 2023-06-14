#include <iostream>
//#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
    int *wait;
    int maxLen;
    //Текущий размер очереди
    int qLen;

public:
    //Конструктор
    Queue(int m);
    //Деструктор
    ~Queue();
    //Добавление элемента
    void push(int c);
    //Извлечение элемента
    int pop();
    //Очистка очереди
    void clear();
    //Проверка существования элементов в очереди
    bool isEmpty();
    //Проверка на переполнение очереди
    bool isFull();
    // Количество элементов в очереди 
    int getCount();
    //демонстрация очереди
    void show();
};

void Queue::show()
{
    cout << "\n-----------------------------------\n";
    for (int i = 0; i < qLen; i++)
        cout << wait[i] << " ";
    cout << "\n-----------------------------------\n";
}
Queue::Queue(int m) { 
    maxLen = m;
    wait = new int[maxLen];
    qLen = 0;
}
Queue::~Queue() { delete[] wait; }
void Queue::clear() { qLen = 0; }
bool Queue::isEmpty() { return qLen == 0; }
bool Queue::isFull() { return qLen == maxLen; }
int Queue::getCount() { return qLen; }
void Queue::push(int c) 
{
    if (!isFull())
        wait[qLen++] = c;
}
int Queue::pop()
{
    if (isEmpty()) 
        return -1;

    int temp = wait[0];
    for (int i = 1; i < qLen; i++)
        wait[i - 1] = wait[i];
            qLen--;
    return temp;
}

int main()
{
    srand(time(0));

    Queue QU(25);
    for (int i = 0; i < 5; i++)
        QU.push(rand() % 50);

    QU.show();
    QU.pop();
    QU.show();
}