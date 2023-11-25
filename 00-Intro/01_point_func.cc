#include <stdio.h>

struct PointStruct {
    int x_;
    int y_;
};
void Print(PointStruct p) {
	printf("(%d,%d)\n", p.x_, p.y_);
}

int main()
{
    // functional style
    PointStruct pointS{3, 4};
    Print(pointS);

	return 0;
}