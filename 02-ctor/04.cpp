#include <iostream>

struct Point {
private: 
    int x_;
    int y_;
	char* name_ = nullptr;
public: 
	Point(): Point(0, 0) {}
	Point(int xy): Point(xy, xy) {}
	Point(int x, int y, const char* name = "noname"){
		name_ = new char[strlen(name)+1];
		strcpy(name_, name);

		std::cout << "Object created\n";
	}
	~Point() {
		delete name_;
		
		std::cout << "Object deleted\n";
	}
};

int main()
{
    Point* point;
	point = new Point();// Object created
	delete point;		// Object deleted

	return 0;
}