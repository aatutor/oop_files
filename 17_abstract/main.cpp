#include <iostream>
#include <string.h>
using namespace std;

struct Point {
	int x, y;
};

class Figure {};

class Triangle: public Figure {
public:
	Triangle(Point,Point,Point){}
};
class Tetragon: public Figure {
public:
	Tetragon(Point*){}
};

void Foo(Figure** arr, int size){}

int main ()
{
	{	
		Point p[4] {
			{0,0}, {0,3}, {4,4}, {5,1}
		};
		Figure* figures[4] = {
			new Triangle(p[0],p[1],p[3]),
			new Tetragon(p)
		};
							
		Foo(figures, 4);
	}
	return 0;
}
