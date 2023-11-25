#include <iostream>

#define DEF 1

struct Point {
private: 
#if DEF
    int x_;
    int y_;
#else
    int x_ = 0; // инциализация
    int y_ = 0; // по умолчанию
#endif
public: 
#if DEF
    Point() { // конструктор
		x_ = 0; // тело
		y_ = 0; // конструктора
#else
	Point(): x_(0), y_(0){ // список инициализации
#endif
		std::cout << "Object created\n";
	}
	~Point() {
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