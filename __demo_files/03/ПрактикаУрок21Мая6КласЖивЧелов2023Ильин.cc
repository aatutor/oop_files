/*Практика 21Мая2023 ООП Урок Ильин В. В. Группа ВБД221 _23Мая2023
2) Реализовать классы "Голова"(Head), "Руки"(Hands), "Ноги"(Legs), "Крылья"(Wings), "Лапы"(Paws).
- Голова имеет поля с цветом волос / шерсти(char) и формой лица / морды(char[50]).
- Руки имеют длину.
- Ноги имеют длину.
- Крылья имеют длину и площадь.
- Лапы имеют количество и скорость.

- Описать класс "Человек"(Human), производный от головы, рук и ног.
- Описать класс "Птица"(Bird), производный от головы, крыльев и ног.
- Описать класс "Пес"(Dog), производный от головы и лап.
Реализовать:
-инициализацию полей в конструкторах
- методы вывода информации об объектах производных классов

Протестировать работу с объектами.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string>
#include <Windows.h>

using namespace std; //здесь находится swap
#include <iostream>

//класс Голова, имеют цвет волос/шерсти и форму лица/морды
class Head
{
  public:
	char color_[20]; //цвет волос/шерсти
	char face_[50];  //форма лица/морды

	Head(const char color[], const char face[])
	{
		strcpy_s(color_, color); //вызов функции strcpy_s из библиотеки <string.h>
		strcpy_s(face_, face);
	}
};

//класс Руки, имеют длину
class Hands
{
  public:
	int lengthArm_; //длина рук
	Hands() : lengthArm_(0){};
	Hands(int lengthArm) : lengthArm_(lengthArm) {}
};

//класс Ноги, имеют длину
class Legs
{
  public:
	int length_; //длина
	Legs(int length) : length_(length) {}
};

//класс Крылья, имеют длину и площадь
class Wings
{
  public:
	int wingspan_; //размах крыльев
	int square_;   //площадь
	Wings(int wingspan, int square) : wingspan_(wingspan), square_(square) {}
};

//класс Лапы, имеют количество и скорость
class Paws
{
  public:
	int number_; //длина
	int speed_;  //площадь
	Paws(int number, int speed) : number_(number), speed_(speed) {}
};
//класс "Человек"(Human), производный от головы, рук и ног.

class Human : public Head, public Hands, public Legs
{ //идёт наследование

	char name_[25];

  public:
	//1 конструктор
	Human(Head h1, Hands h2, Legs l, const char name[]) : Head(h1), Hands(h2), Legs(l)
	{
		strcpy_s(name_, name);
	}
	//2 конструктор
	Human(const char name[], const char color[], const char face[], int length, int lengthArm) : Head(color, face), Hands(lengthArm), Legs(length)
	{
		strcpy_s(name_, name); //вызов функции strcpy_s из библиотеки <string.h>
		strcpy_s(color_, color);
		strcpy_s(face_, face);
	}
	void Print()
	{
		cout << "/ Имя " << name_ << " / Цвет волос " << color_ << " / Форма лица " << face_ << "/ Размер стопы " << length_ << " / Размер руки " << lengthArm_ << endl;
	}

	void Test1()
	{
		cout << " Объект Человек \n";
		Print();
	}
};

//класс "Птица"(Bird), производный от головы, крыльев и ног.
class Bird : public Head, public Wings, public Legs
{ //идёт наследование
	char name_[10];

  public:
	//конструктор 2
	Bird(const char name[], const char color[], const char face[], int wingspan, int square, int length) : Head(color, face), Wings(wingspan, square), Legs(length)
	{
		strcpy_s(name_, name);
		strcpy_s(color_, color);
		strcpy_s(face_, face);
	}
	void Print()
	{
		cout << "/ Вид " << name_ << " / Окрас " << color_ << " / Морда " << face_ << " / Размах крыльев " << wingspan_ << " / Площадь крыльев " << square_ << " / Длина ног " << length_ << endl;
	}
	void Test2()
	{
		cout << "\n  Объект Птица \n";
		Print();
	}
};
//класс "Пес"(Dog), производный от головы и лап.
class Dog : public Head, public Paws
{ //идёт наследование
	char name_[10];

  public:
	//конструктор 2
	Dog(const char name[], const char color[], const char face[], int number, int speed) : Head(color, face), Paws(number, speed)
	{
		strcpy_s(name_, name);
		strcpy_s(color_, color);
		strcpy_s(face_, face);
	}
	void Print()
	{
		cout << "/ Вид " << name_ << " / Окрас " << color_ << " / Морда " << face_ << " / Количество лап " << number_ << " / Скорость " << speed_ << endl;
	}
	void Test3()
	{
		cout << " \n Объект Собака \n";
		Print();
	}
};
int main()
{
	setlocale(LC_ALL, "Ru");
	Human humanoid1("Иван Новгородский", "black", "oval", 44, 30);
	humanoid1.Test1();

	Bird bird1("Eagle", "white", "acute", 1, 2, 5);
	bird1.Test2();

	Dog dog1("Hound", "чёрно-белая", "вытянутая", 4, 45);
	dog1.Test3();
}
