#include <stdio.h>

class Point {
	int x_;
	static int commonY_;
public:
	Point (): x_(0) {}
	Point (int x): x_(x) {}
	static void SetCommonY(int x) {
		commonY_ = x;
	}
	static int GetCommonY() {
		return commonY_;
	}
};

int Point::commonY_ = 3;

int main ()
{
	printf("%d\n", Point::GetCommonY());
	Point::SetCommonY(5);
	printf("%d\n", Point::GetCommonY());

    return 0;
}
