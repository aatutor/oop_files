#include <iostream>
using namespace std;

struct Student{
	char name_[20];
	int age_;

	void Init(char* name, int age){

	}
	void Print(){

	}
}
void Test1()
{
	Student stud1;
	stud1.Init("Ivan", 18);
	stud1.Print();

	Student stud2;
	stud2.Init("Petr", -1);
	stud2.Print();

	Student stud3;
	stud3.Init("", 1);
	stud3.Print();
}
void Test()
{
{
	Student stud;
	stud.Init("Ivan", 18);
	stud.Print();
}
{
	Student stud;
	stud.Init("Petr", -1);
	stud.Print();
}
{
	Student stud;
	stud.Init("", 1);
	stud.Print();
}
}
void Menu()
{
	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;

		cin >> b;
		try
		{
			cout << Div(a, b) << endl;
		}
		catch(int error)
		{
			cout << "Inf\n";
		}
	}
}

int main ()
{
    // Test();
    Menu();

	return 0;
}

/*
input: 1 2
0.5
input: 1 3
0.333333
input: 2 0
Inf
input: 3 4
0.75
input: 0
*/