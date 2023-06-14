#include <iostream>
#include <list>
using namespace std;
typedef list<int> ourList;
void ShowLists(ourList &l1, ourList &l2)
{
	//Создаем итератор.
	ourList::iterator iter;
	cout << "list1: ";
	for (iter = l1.begin(); iter != l1.end(); iter++)
	{
		//выводим элемент на который указывает итератор
		cout << *iter << " ";
	}
	cout << endl
		 << "list2: ";
	for (iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl
		 << endl;
}
void main()
{
	//Создание двух пустых списков
	ourList list1, list2;
	//Заполнение обоих списков элементами
	for (int i = 0; i < 6; ++i)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	//вывод списков на экран
	ShowLists(list1, list2);
	//Во втором списке перемещение
	//первого элемента в конец
	list2.splice(list2.end(),	//Позиция в приемник
				 list2,			 //Источник
				 list2.begin()); //Позиция в источнике
	//"переворачиваем" первый список
	list1.reverse();
	ShowLists(list1, list2);
	//Сортировка обоих списков
	list1.sort();
	list2.sort();
	ShowLists(list1, list2);
	//Сливаем два отсортированных списка
	//в первый спискок
	list1.merge(list2);
	ShowLists(list1, list2);
	//удаляем дубликаты из первого списка
	list1.unique();
	ShowLists(list1, list2);
}