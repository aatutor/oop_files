
void FunctionalStyle()
{
    int* arr = new int[6]{1, 2, 2, 5, 3, 1};

    Sort(arr, 6);
    Print(arr, 6);
    cout << "summ: " << Sum(arr, 6) << endl;
}

void OopStyle()
{
    Arr arr({1, 2, 2, 5, 3, 1});

    arr.Sort();
    arr.Print();
    cout << "summ: " << arr.Sum() << endl;
}