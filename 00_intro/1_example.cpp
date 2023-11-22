// Вычислить среднюю оценку студента
#include <stdio.h>
using namespace std;

struct PointStruct {
    int x_;
    int y_;
};
void Print(PointStruct p) {
	printf("(%d,%d)\n", p.x_, p.y_);
}

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
    // struct style
    PointStruct pointS{3, 4};
    Print(pointS);

    // class style
    PointClass pointC{6, 8};
    pointC.PrintInline();
    pointC.PrintGlobal();

	return 0;
}