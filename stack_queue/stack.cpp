#include <iostream>
//#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
    //Нижняя и верхняя границы стека
    enum { EMPTY = -1, FULL = 10 };
    //Массив для хранения данных
    char st[FULL + 1];
    //Указатель на вершину стека
    int top;

  public:
    //Конструктор
    Stack();
    //Добавление элемента
    void push(char c);
    //Извлечение элемента
    char pop();
    //Очистка стека
    void clear();
    //Проверка существования элементов в стеке
    bool isEmpty();
    //Проверка на переполнение стека
    bool isFull();
    //Количество элементов в стеке
    int getCount();
};

Stack::Stack() { top = EMPTY; }
bool Stack::isEmpty() { return top == EMPTY; }
bool Stack::isFull() { return top == FULL; }
int Stack::getCount() { return top + 1; }
void Stack::clear() { top = EMPTY; }

void Stack::push(char c)
{
    if (!isFull())
        st[++top] = c;
}
char Stack::pop()
{
    if (isEmpty())
        return 0;
    return st[top--];
}

int main()
{
    srand(time(0));
    Stack ST;
    char c;
    //пока стек не заполнится
    while (!ST.isFull())
    {
        c = rand() % 4 + 2;
        cout << (int)c << " ";
        ST.push(c);
    }
    cout << endl;
    //пока стек не освободится
    while (c = ST.pop())
    {
        cout << (int)c << " ";
    }
    cout << "\n\n";

    return 0;
}
