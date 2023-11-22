#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Point {
	int x_;
	int y_;
public:
	virtual void Info() {
		cout <<"O("<< x_ <<","<< y_ <<")\n";
	}
};

class Circle: public Point {
	double r_;
public:
	void Info() override {
		cout <<"Radius: "<< r_ << endl;
	}
};
class Square: public Point {
	int a_;
public:
	void Info() override {
		cout <<"Side: "<< a_ << endl;
	}
};


void Test() 
{
	using namespace std;
	{
		Point* p = new Point();
		p->Info();
	}
	cout << string(15, '-') << endl;
	{
		Point* arr[3] {
			new Point(),
			new Circle(),
			new Square()
		};
		for(int i=0; i!=3;++i)
			arr[i]->Info();
	}
	cout << string(15, '-') << endl;
	{
	}
	cout << string(15, '-') << endl;
	{
	}
}

int main ()
{
	Test();

	return 0;
}
