#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//Создаем вектор
	vector<int> vect;
	cout << "\nNumber of elements that could be
		stored in the vector without "
		 << "allocating more storage --> "
		 << vect.capacity();
	cout << "\n-----------------------------------";
	//используя метод size() получаем текущее кол-во
	//элементов в векторе.
	cout << "\nThe number of elements in the vector --> " << vect.size();
	cout << "\n-----------------------------------";
	vect.resize(4, 0); //изменяем размер, новые
	//элементы заполнятся нулями
	cout << "\nResizing...\n";
	cout << "The number of elements in
			the vector-- >
		" << vect.size() << endl;
			cout
			<< "\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-----------------------------------";
	//максимальный размер вектора.
	//Метод max_size() возвращает кол-во байт.
	cout << "\nThe maximum possible length of the
			vector-- >
		"
			<< vect.max_size() / 4;
	cout << "\n-----------------------------------";
	vect.push_back(1); //вставляем единицу
	//в конец вектора
	cout << "\npush_back\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-----------------------------------";
	//создаем реверсный итератор и выставлем
	//его на конец вектора
	vector<int>::reverse_iterator i_riterator =
		vect.rbegin();
	cout << "\nreverse_iterator\nvector -->\t";
	//выводим содержимое векртора на экран используя
	//реверсный итератор
	for (int i = 0; i < vect.size(); i++)
	{
		cout << *(i_riterator + i) << '\t';
	}
	cout << "\n-----------------------------------";
	//создаем обычный итератор и выставлем его
	//на конец вектора
	vector<int>::iterator i_iterator = vect.end();
	//вставка элемента "-1" перед последним элементом
	vect.insert(i_iterator - 1, -1);
	cout << "\ninsert\nvector -->\t";
	//выводим содержимое векртора на экран
	//используя обычный итератор
	for (i_iterator = vect.begin();
		 i_iterator != vect.end(); i_iterator++)
	{
		cout << *(i_iterator) << '\t';
	}
	cout << "\n-----------------------------------";
	i_iterator = vect.end();		   //итератор конца вектора
	vect.insert(i_iterator - 1, 2, 4); //вставка двух
	//четверок перед
	//последним
	//элементом
	cout << "\ninsert\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << '\t';
	}
	cout << "\n-------------------------------\n\n";
}