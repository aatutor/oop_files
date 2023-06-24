// more examples: https://www.geeksforgeeks.org/vector-in-cpp-stl/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void ShowVector(vector<int> vect)
{
	cout << "\nvector ["<< vect.size() <<"] -->\t";
	for (auto iter = vect.begin(); iter != vect.end(); ++iter)
	{
		cout << *iter << '\t';
	}
	cout << "\n-----------------------------------\n";
}
void ShowReverceVector(vector<int> vect)
{
	cout << "\nvector ["<< vect.size() <<"] -->\t";
	for (auto iter = vect.rbegin(); iter != vect.rend(); ++iter)
	{
		cout << *iter << '\t';
	}
	cout << "\n-----------------------------------\n";
}

int main()
{
	//—оздаем вектор
	vector<int> vect;

	for(int i = 5; i != 0; --i)
		vect.push_back(i);	

	cout << "Size : " << vect.size();
    cout << "\nCapacity : " << vect.capacity();
    cout << "\nMax_Size : " << vect.max_size();
	ShowVector(vect);
 
	cout << "\nInsert 0:";
	vect.push_back(0); 	//вставл€ем нуль
						//в конец вектора
	ShowVector(vect);

	cout << "\nReversed:";
	ShowReverceVector(vect);

	cout << "\nResize(to 3 and to 6):";
	vect.resize(3); 	//измен€ем размер	
	ShowVector(vect);

	vect.resize(6, 0); 	//измен€ем размер, новые 
						//элементы заполн€тс€ нул€ми
	cout << "set last to 10:";
	vect[vect.size()-1] = 10;	// последний эл-т = 10
	ShowVector(vect);

	cout << "\nInsert -5:";
	vect.insert(vect.end() - 1, 2, -5); //вставка двух значений
	ShowVector(vect);
}