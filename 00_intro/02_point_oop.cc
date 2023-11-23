#include <stdio.h>

struct PointClass {
    int x_;
    int y_;
    void PrintInline(){
		printf("(%d,%d)\n", x_, y_);
    }
    void PrintGlobal();
};
void PointClass::PrintGlobal(){
	printf("(%d,%d)\n", x_, y_);
}

int main()
{
    // oop style
    PointClass pointC{6, 8};
    pointC.PrintInline();
    pointC.PrintGlobal();

	return 0;
}