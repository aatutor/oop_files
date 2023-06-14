#include <iostream>

template <typename T>
void print(T* begin, T* end, char delimiter = ' ')
{
    while (begin != end)
    {
        std::cout << *begin++ << delimiter;
    }
    std::cout << '\n';
}

template <typename T, typename Predicate>
int copy_if(T* srcB, T* srcE, T* destB, T* destE, Predicate pred)
{
    int copyCount{ 0 };
    while (destB != destE and srcB != srcE)
    {
        if (pred(*srcB))
        {
            *destB++ = *srcB;
            ++copyCount;
        }
        ++srcB;
    }
    return copyCount;
}

bool odd(const int el)
{
    return el % 2 != 0;
}

bool even(const int el)
{
    return el % 2 == 0;
}

bool greater3(const int el)
{
    return el > 3;
}

bool all(const int el)
{
    return true;
}

int main()
{
    const int size{ 10 };
    int arr1[size]{ 1,2,3,4,5,6,7,8,9,10 };
    int arr2[size]{};

    /*
    * указатель на первый элемент, начало - массива arr1 - arr1Begin
    * указатель на следующий за последним элемент, конец - массива arr1 - arr1End
    */
    int* const arr1Begin{ arr1 };
    int* const arr1End{ arr1 + size };

    /*
    * указатель на первый элемент, начало - массива arr2 - arr2Begin
    * указатель на следующий за последним элемент, конец - массива arr2 - arr2End
    */
    int* const arr2Begin{ arr2 };
    int* const arr2End{ arr2 + size };

    /*
    * указатель на следующий, за последним скопированным в массив arr2 элемент - arr2NewEnd
    */
    int* arr2NewEnd{};

    std::cout << "Original arr1:\n";
    print(arr1, arr1 + size);
    std::cout << "Original arr2:\n";
    print(arr2, arr2 + size);
    std::cout << '\n';

    std::cout << "arr2 copy of arr1 even elements only:\n";
    arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, even);
    print(arr2, arr2NewEnd);
    std::cout << '\n';

    std::cout << "arr2 copy of arr1 odd elements only:\n";
    arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, odd);
    print(arr2, arr2NewEnd);
    std::cout << '\n';

    std::cout << "arr2 copy of arr1 elements greater 3 only:\n";
    arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, greater3);
    print(arr2, arr2NewEnd);
    std::cout << '\n';

    std::cout << "arr2 copy of arr1 all elements:\n";
    arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, all);
    print(arr2, arr2NewEnd);
    std::cout << '\n';

    return 0;
}