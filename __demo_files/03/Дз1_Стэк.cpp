//Используем цикл switch case:
//Дз1 _03 мая2023 сдать 
//Есть строка символов, признаком конца, которой является «; ».В строке могут быть
//фигурные, круглые, квадратные скобки.Скобки могут быть открывающими и закрывающими.
//Необходимо проверить корректность расстановки скобок.
//При этом необходимо, чтобы выполнились следующие правила :

//1.       Каждая открывающая скобка должна иметь справа такую же закрывающую.
//Обратное также должно быть верно.
//2.       Открывающие  и  закрывающие  пары  скобок  разных  типов  должны  быть правильно расположены по отношению друг к другу.

//–      Пример правильной строки :

//({ x - y - z }*[x + 2y] - (z + 4x));

//–      Пример неправильной строки :

//([x - y - z}*[x + 2y) - {z + 4x)].

//Если все правила   соблюдены, выведите информационное сообщение корректности  строк и, иначе покажите строку до места  возникновения  первой ошибки.
//Используйте класс Stack для выполнения этой задачи.

#include <stdio.h>
#include <iostream>
#include <Windows.h>//для понимания русских символов

#include <string>
using namespace std;

class Stack {
private:
    enum { EMPTY = -1, FULL = 100 };//FULL - размер символьного массива      
    char data[FULL+1];//массив символов
    int top_;//вершина стэка
    string line;

public:
    Stack() {
        top_ = EMPTY;
    }
    //конструктор
    Stack(const std::string& line) {
        top_ = -1;
        this->line = line;
        for (char c : line) {
            push(c);
        }
    }
    void push(char c) {//положить в стэк
        if (top_ == FULL - 1) {
            cout << "Ошибка: стек переполнен\n";
            return;
        }
        top_++;
        data[top_] = c;
    }

    char pop() {// извлечь из стэка
        if (top_ == -1) {
            cout << "Ошибка: стек пуст\n";
            return '\0';
        }
        char c = data[top_];
        top_--;
        return c;
    }

    bool isEmpty() const {// если стэк пуст
        return top_ == EMPTY;
    }

    bool isFull() const {// если стэк полон
        return top_ == FULL - 1;
    }

    char peek() const {
        if (top_ == EMPTY) {
            cout << "Ошибка: стек пуст\n";
            return '\0';
        }
        return data[top_]; //посмотреть в стэк
    }

    // В методе используем стек для проверки парности скобок в строке. 
    bool checkBrackets(const std::string& line) {
        int pos = 0;
        for (char c : line) {//Проходим по всем символам строки по порядку.
            pos++;
            switch (c) {
            case '(':
            case '[':
            case '{'://Если символ является открывающей скобкой (то есть `(`, `[` или `{`),добавляем ее в стек с помощью метода push()
                push(c);
                break;
//Если символ является закрывающей скобкой (то есть `)`, `]` или `}`),проверяем, соответствует ли она последней добавленной скобке в стеке:
            case ')':
                if (isEmpty() || peek() != '(') {//если стэк пуст, и равны ли скобки?
                    cout << "\n Неправильные скобки, Позиция: " << pos << "\n";
                    cout << line.substr(0, pos) << "\n";
                    return false;
                }
//Если последняя добавленная скобка соответствует данной закрывающей скобке, удаляем последнюю добавленную скобку из стека с помощью метода pop()
                else {
                    pop();
                }
                break;
            case ']':
                if (isEmpty() || peek() != '[') {
                    cout << "\n Неправильные скобки, Позиция: " << pos << "\n";
                    cout << line.substr(0, pos) << "\n";
                    return false;
                }
                else {
                    pop();
                }
                break;
            case '}':
                if (isEmpty() || peek() != '{') {
                    cout << "\n Неправильные скобки, Позиция " << pos << "\n";
                    cout << line.substr(0, pos) << "\n";
                    return false;
                }
                else {
                    pop();
                }
                break;
            default:
                // Если символ не является скобкой, мы его игнорируем
                break;
            }
        }

        return isEmpty();
    }
    
    void print(string& line)const // вывод строки на экран
    {
        cout << "Строка: " << line << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);//для понимания русских символов
    SetConsoleOutputCP(1251);
    string line;
    Stack s3;
    Stack s1, s2;
    string line1 = "({x - y - z}*[x + 2y] - (z + 4x))";

    string line2 = "([x-y-z}*[x+2y)-{z+4x)]";

    s1.print(line1);// печать нашей строки
    if (s1.checkBrackets(line1)) {
        cout << "Скобки расставлены корректно\n";
    }
    else {
        cout << "Ошибка: некорректная расстановка скобок\n";
    }
    s2.print(line2);// печать нашей строки
    if (s2.checkBrackets(line2)) {
        cout << "Скобки расставлены корректно\n";
    }
    else {
        cout << "Ошибка: некорректная расстановка скобок\n";
    }
    cout << "Введите строку для проверки скобок: ";
    getline(std::cin, line);
    if (s3.checkBrackets(line)) {
        cout << "Скобки расставлены корректно\n";
    }
    else {
        cout << "Ошибка: некорректная расстановка скобок\n";
    }
    //s2.checkBrackets(line2);
    cout << s2.pop();
    cout << s2.pop();
    cout << s2.pop();
    cout << s2.pop();
    system("pause");
    return 0;
}
