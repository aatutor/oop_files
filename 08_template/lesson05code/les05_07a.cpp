// les05_07a
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

template<class T>
class List
{
    vector<T> list;
public:
    void add(T item)
    {
        list.push_back(item);
    }

    void remove(int index)
    {
        list.erase(list.begin() + index);
    }

    auto getMin()
    {
        auto pMin = list.begin();
        for (auto it = list.begin(); it < list.end(); it++)
        {
            if (*it < *pMin)
            {
                pMin = it;
            }
        }
        return *pMin;
    }

    auto getMax()
    {
        auto pMax = list.begin();
        for (auto it = list.begin(); it < list.end(); it++)
        {
            if (*it > *pMax)
            {
                pMax = it;
            }
        }
        return *pMax;
    }
};

template<>
class List<const char*>
{
    vector<const char*> list;
public:
    void add(const char* item)
    {
        list.push_back(item);
    }

    void remove(int index)
    {
        list.erase(list.begin() + index);
    }

    auto getMin()
    {
        auto pMin = list.begin();
        for (auto it = list.begin(); it < list.end(); it++)
        {
            if (strcmp(*it, *pMin) < 0)
            {
                pMin = it;
            }
        }
        return *pMin;
    }

    auto getMax()
    {
        auto pMax = list.begin();
        for (auto it = list.begin(); it < list.end(); it++)
        {
            if (strcmp(*it, *pMax) > 0)
            {
                pMax = it;
            }
        }
        return *pMax;
    }
};

int main()
{
    List<int> intList;
    intList.add(4);
    intList.add(5);
    intList.add(2);
    intList.add(3);
    cout << "intList min: " << intList.getMin() << endl;
    cout << "intList max: " << intList.getMax() << endl << endl;

    List<string> strList;
    strList.add("four");
    strList.add("five");
    strList.add("two");
    strList.add("three");
    cout << "strList min: " << strList.getMin() << endl;
    cout << "strList max: " << strList.getMax() << endl << endl;

    List<const char*> txtList;
    txtList.add("four");
    txtList.add("five");
    txtList.add("two");
    txtList.add("three");
    cout << "txtList min: " << txtList.getMin() << endl;
    cout << "txtList max: " << txtList.getMax() << endl << endl;

    _getch();
}

