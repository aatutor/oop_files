#include <iostream>
#include <map> //map,multimap -- отбражение,
//мультиотображение (отображение
//с повторениями)
#include <string>
using namespace std;
//шаблонная функция для вывода содержимого отбражения
//или мультиотображения на экран
template <class container>
void show(container col)
{
	for (container::const_iterator i = col.begin();
		 i != col.end(); ++i)
	{
		cout << i->first << '\t' << i->second << endl;
	}
	cout << endl
		 << endl;
}
void main()
{
	cout << "map\n\n";
	//Создаем пустой контейнер (отображение)
	map<string, int> cont;
	//Создаем пустой контейнер (мультиотображение)
	multimap<string, int> multicont;
	//добавляем две пары в отображение
	cont.insert(pair<string, int>("Ivanov", 10));
	cont.insert(pair<string, int>("Petrov", 20));
	//добавится пара "Sidorov, 30"
	cont["Sidorov"] = 30;
	show(cont);
	//заменится значение в паре с ключем "Ivanov"
	cont["Ivanov"] = 50;
	show(cont);
	//Элемент не добавится, т.к. пара
	//с ключем "Ivanov" уже существует
	cont.insert(pair<string, int>("Ivanov", 100));
	show(cont);
	/////////////////////////////////////////////////
	cout << "------------------------\nmultimap\n\n";
	multicont.insert(pair<string, int>("Ivanov", 10));
	multicont.insert(pair<string, int>("Petrov", 20));
	multicont.insert(pair<string, int>("Sidorov", 20));
	//Для мульти отображения не определен оператор "[]"
	//multicont["Sidorov"] = 30; //Error
	show(multicont);
	//Добавляем пару ("Ivanov",100)
	multicont.insert(pair<string, int>("Ivanov", 100));
	show(multicont);
	//Ишем первое вхождение элемента с ключем "Petrov"
	multimap<string, int>::iterator iter =
		multicont.find("Petrov");
	cout << iter->first << '\t' << iter->second
		 << endl
		 << endl;
	cout << "Count of key \"Ivanov\" in multimap = "
		 << multicont.count("Ivanov") << endl;
	//возвращает итератор, указывающий на первое включение
	//данного ключа или на конец отображения
	//в случае отсутствия
	iter = multicont.lower_bound("Ivanov");
	for (; iter != multicont.upper_bound("Ivanov") && iter != multicont.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
	cout << endl << endl;
}