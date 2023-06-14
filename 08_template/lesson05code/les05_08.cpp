// les05_08

#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

template <class T, int height, int width>
class Matrix
{
    T m[height][width];
public:
    const auto& operator()(int j, int i) const
    {
        if (j < 0 || j >= height
            || i < 0 || i >= width)
        {
            throw "Matrix index error!";
        }

        return m[j][i];
    }

    auto& operator()(int j, int i)
    {
        if (j < 0 || j >= height
            || i < 0 || i >= width)
        {
            throw "Matrix index error!";
        }

        return m[j][i];
    }

    auto getMin()
    {
        auto min = m[0][0];
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                if (m[j][i] < min)
                {
                    min = m[j][i];
                }
            }
        }
        return min;
    }

    auto getMax()
    {
        auto max = m[0][0];
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                if (m[j][i] > max)
                {
                    max = m[j][i];
                }
            }
        }
        return max;
    }
};

int main()
{
    // const int height = 2;
    // const int width = 3;

    Matrix<int, 2, 3> intMatrix;
    intMatrix(0, 0) = 5;
    intMatrix(0, 1) = 1;
    intMatrix(0, 2) = 9;
    intMatrix(1, 0) = 15;
    intMatrix(1, 1) = 11;
    intMatrix(1, 2) = 19;
    cout << "intMatrix min: " << intMatrix.getMin() << endl;
    cout << "intMatrix max: " << intMatrix.getMax() << endl << endl;

    Matrix<string, height, width> strMatrix;
    strMatrix(0, 0) = "five";
    strMatrix(0, 1) = "one";
    strMatrix(0, 2) = "nine";
    strMatrix(1, 0) = "fifteen";
    strMatrix(1, 1) = "eleven";
    strMatrix(1, 2) = "nineteen";
    cout << "strMatrix min: " << strMatrix.getMin() << endl;
    cout << "strMatrix max: " << strMatrix.getMax() << endl << endl;

    Matrix<const char*, height, width> txtMatrix;
    txtMatrix(0, 0) = "five";
    txtMatrix(0, 1) = "one";
    txtMatrix(0, 2) = "nine";
    txtMatrix(1, 0) = "fifteen";
    txtMatrix(1, 1) = "eleven";
    txtMatrix(1, 2) = "nineteen";
    cout << "txtMatrix min: " << txtMatrix.getMin() << endl;
    cout << "txtMatrix max: " << txtMatrix.getMax() << endl << endl;

    _getch();
}

