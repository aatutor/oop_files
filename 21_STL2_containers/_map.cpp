#include <iostream>
#include <map>
#include <vector>
using namespace std;

void main()
{
	// создаем отображение
	map<int, int> our_map;
	//создаем вектор
	vector<int> our_vector;
	//максимальный размер вектора
	cout << "\n\nmax size of vector --> "
		 << our_vector.max_size() / sizeof(int);
	//максимальный размер отображения
	//(в два раза меньше т.к. для каждого элемента
	//нужно хранить два значения - пару).
	cout << "\n\nmax size of map --> "
		 << our_map.max_size() / sizeof(int);
	cout << "\n\n-------------------------------\n";

	int val;
	int key;
	cout << "\nInput value : ";
	cin >> val;
	cout << "\nInput key : ";
	cin >> key;

	//создаем пару на основании двух значений.
	pair<int, int> element(key, val);
	//вставляем пару в отображение
	our_map.insert(element);
	//кол-во элементов в отображении
	cout << "\nCurrent element of map --> "
		 << our_map.size() << endl;
	cout << "\n\n-------------------------------\n";

	cout << "\nInput value : ";
	cin >> val;
	cout << "\nInput key : ";
	cin >> key;
	
	pair<map<int, int>::iterator, bool> err = our_map.insert(make_pair(key, val));
	if (err.second == false)
	{
		//отработает в случае если в отображение
		//не получилось добавить элемент
		//например если в отображении уже был
		//элемент с данным ключом.
		cout << "\nError !!!\n";
	}
	//кол-во элементов в отображении
	cout << "\nCurrent element of map --> "
		 << our_map.size() << endl;
	//вывод всех элементов на экран
	map<int, int>::iterator iter = our_map.begin();
	for (; iter != our_map.end(); iter++)
	{
		cout << "\nKey --> " << iter->first
			 << "\t\tValue --> " << iter->second;
	}
	cout << "\n---------------------------------\n";
}