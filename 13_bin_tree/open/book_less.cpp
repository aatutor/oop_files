#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

struct Elem
{
    int key;
    Elem* left, *right, *parent;
};

class Tree
{
    //корень
    Elem* root_ = nullptr;

public:
    ~Tree();
    //Печасть всего содержимого
    void Print();
    //печать от указанного узла
    void Print(Elem*);
    //поиск от указанного узла
    Elem* Search(Elem*, int key);
    //min от указанного узла
    Elem* Min(Elem*);
    //max от указанного узла
    Elem* Max(Elem*);
    //следующий для указанного узла
    Elem* Next(Elem*);
    //предыдущий для указанного узла
    Elem* Previous(Elem*);
    //вставка узла
    void Insert(Elem*);
    //удаление ветки для указанного узла,
    //0 - удаление всего дерева
    void Delete(Elem*);
    //получить корень
    Elem* GetRoot();
};
//Рекурсивный обход дерева
void Tree::Print(Elem* node) {
    if (node == 0)
        return;

    Print(node->left);
    cout << node->key << " ";
    Print(node->right);
}
void Tree::Print() {
    cout << "Tree values: ";
    Print(root_);
    cout << endl;
}
Elem* Tree::Search(Elem* node, int key) {
    //Пока есть узлы и ключи не совпадают
    while (node != 0 && key != node->key)
    {
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}
Elem* Tree::Min(Elem* node) {
    //Поиск самого "левого" узла
    if (node != 0)
        while (node->left != 0)
            node = node->left;
    return node;
}
Elem* Tree::Max(Elem* node) {
    //Поиск самого "правого" узла
    if (node != 0)
        while (node->right != 0)
            node = node->right;
    return node;
}
Elem* Tree::Next(Elem* node) {
    if (node == 0)
        return nullptr;

    //если есть правый потомок
    if (node->right != 0)
        return Min(node->right);

    //родитель узла
    Elem* parent = node->parent;
    //если node не корень и node справа
    while (parent != 0 && node == parent->right)
    {
        //Движемся вверх
        node = parent;
        parent = node->parent;
    }
    return parent;
}
Elem* Tree::Previous(Elem* node) {
    if (node == 0)
        return nullptr;

    //если есть левый потомок
    if (node->left != 0)
        return Max(node->left);

    //родитель узла
    Elem* parent = node->parent;
    //если node не корень и node слева
    while (parent != 0 && node == parent->left)
    {
        //Движемся вверх
        node = parent;
        parent = node->parent;
    }
    return parent;
}
Elem* Tree::GetRoot() {
    return root_;
}
void Tree::Insert(Elem* node) {
    //потомков нет
    node->left = nullptr;
    node->right = nullptr;

    //поиск места
    if (root_ == 0) {//элемент первый (единственный)
        root_ = node;
        return;
    }
        
    Elem* temp = root_;
    Elem* parent = nullptr;
    bool flag;
    while (temp != 0)
    {
        //будущий родитель
        parent = temp;
        flag = node->key < temp->key;
        if (flag)
            temp = temp->left;
        else
            temp = temp->right;
    }
    //заполняем родителя
    node->parent = parent;
    //чей ключ больше?
    if (flag)
        parent->left = node;
    else
        parent->right = node;
}
void Tree::Delete(Elem* node) {
    Elem* temp, *toDelete;
    //не 2 потомка
    if (node->left == 0 || node->right == 0)
        toDelete = node;
    else
        toDelete = Next(node);

    if (toDelete->left != 0)
        temp = toDelete->left;
    else
        temp = toDelete->right;

    if (temp != 0)
        temp->parent = toDelete->parent;

    // Запись в родителя
    if (toDelete->parent == 0)
        //Удаляется корневой узел?
        root_ = temp;
    else if (toDelete == toDelete->parent->left)
        //слева от родителя?
        toDelete->parent->left = temp;
    else
        //справа от родителя?
        toDelete->parent->right = temp;

    if (toDelete != node)
    {
        //Копирование данных узла
        node->key = toDelete->key;
    }
    delete toDelete;
}
Tree::~Tree() {
    while (root_ != 0)
        Delete(root_);
    cout << "~tree_removed\n";
}

int main()
{
    srand(time(0));
    {
        int size = 10;
        Tree arr;
        for(int i=0; i != size; ++i){
            arr.Insert(new Elem{rand()%50});
        }
        //Вывод результатов
        arr.Print();

        cout << "less 10 items: ";
        Elem* mid;
        Elem* el = arr.Min(arr.GetRoot());
        for(int i=0; i != size; ++i){
            int x = el->key;
            if (x < 10)
                cout << x << " ";
            el = arr.Next(el);
            if (i+1 == size/2)
                mid = el;
        }
        cout << "\n";

        cout << mid->key << " removed\n";
        arr.Delete(mid);        
        arr.Print();
    }
    {
        int size = 20;
        Tree arr;
        for(int i=0; i != size; ++i) {
            arr.Insert(new Elem{rand()%10});
        }
        //Вывод результатов
        arr.Print();

        if (arr.Search(arr.GetRoot(), 0) == nullptr)
            cout << "has no '0' item\n";
        else
            cout << "arr has item '0'\n";
    }
}
