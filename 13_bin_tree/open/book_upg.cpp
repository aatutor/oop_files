#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

struct Elem
{
    int ownerPoints;   //Очки хозяина
    int oppPoints;     //Очки соперника
    char match[10];    //Счет
    char name[20];     //Команда
    char opponent[20]; //Соперник
    Elem *left, *right, *parent;
};

class Tree
{
    //корень
    Elem *root_;

public:
    Tree();
    ~Tree();
    //печать от указанного узла
    void Print(Elem *node);
    //поиск от указанного узла
    Elem *Search(Elem *node, const char *name);
    //min от указанного узла
    Elem *Min(Elem *node);
    //max от указанного узла
    Elem *Max(Elem *node);
    //следующий для указанного узла
    Elem *Next(Elem *node);
    //предыдущий для указанного узла
    Elem *Previous(Elem *node);
    //вставка узла
    void Insert(Elem *node);
    //удаление ветки для указанного узла,
    //0 - удаление всего дерева
    void Delete(Elem *node);
    //получить корень
    Elem *GetRoot();
};
Tree::Tree()
{
    root_ = nullptr;
}
Tree::~Tree()
{
    while (root_ != 0)
        Delete(root_);
}
//Рекурсивный обход дерева
void Tree::Print(Elem *node)
{
    if (node == 0)
        return;

    Print(node->left);
    cout << node->name
            << node->match
            << node->opponent
            << endl;
    Print(node->right);
}
Elem *Tree::Search(Elem *node, char *name)
{
    //Пока есть узлы и ключи не совпадают
    while (node != 0 && strcmp(name, node->name) != 0)
    {
        if (strcmp(name, node->name) < 0)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}
Elem *Tree::Min(Elem *node)
{
    //Поиск самого "левого" узла
    if (node != 0)
        while (node->left != 0)
            node = node->left;
    return node;
}
Elem *Tree::Max(Elem *node)
{
    //Поиск самого "правого" узла
    if (node != 0)
        while (node->right != 0)
            node = node->right;
    return node;
}
Elem *Tree::Next(Elem *node)
{
    if (node == 0)
        return nullptr;

    //если есть правый потомок
    if (node->right != 0)
        return Min(node->right);

    //родитель узла
    Elem *parent = node->parent;
    //если node не корень и node справа
    while (parent != 0 && node == parent->right)
    {
        //Движемся вверх
        node = parent;
        parent = node->parent;
    }
    return parent;
}
Elem *Tree::Previous(Elem *node)
{
    if (node == 0)
        return nullptr;

    //если есть левый потомок
    if (node->left != 0)
        return Max(node->left);

    //родитель узла
    Elem *parent = node->parent;
    //если node не корень и node слева
    while (parent != 0 && node == parent->left)
    {
        //Движемся вверх
        node = parent;
        parent = node->parent;
    }
    return parent;
}
Elem *Tree::GetRoot()
{
    return root_;
}
void Tree::Insert(Elem *node)
{
    //потомков нет
    node->left = nullptr;
    node->right = nullptr;

    //поиск места
    if (root_ == 0) {//элемент первый (единственный)
        root_ = node;
        return;
    }
        
    Elem *temp = root_;
    Elem *parent = nullptr;
    bool flag;
    while (temp != 0)
    {
        //будущий родитель
        parent = temp;
        flag = strcmp(node->name, temp->name) < 0;
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
void Tree::Delete(Elem *node)
{
    Elem *temp, *toDelete;
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
        strcpy(node->name, toDelete->name);
        strcpy(node->opponent, toDelete->opponent);
        strcpy(node->match, toDelete->match);
        node->oppPoints = toDelete->oppPoints;
        node->ownerPoints = toDelete->ownerPoints;
    }
    delete toDelete;
}
//Турнирная таблица
Tree tournament;
void Game(char Commands[][20], int N)
{
    int i, j;
    int p1, p2; //Счет
    //Каждая команда играет с каждой по 2 раза -
    //дома и в гостях
    int k;
    Elem *temp;
    for (k = 0; k < 2; k++)
        for (i = 0; i < N - 1; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                temp = new Elem;
                if (k == 0)
                {
                    //1 игра
                    strcpy(temp->name, Commands[i]);
                    strcpy(temp->opponent, Commands[j]);
                }
                else
                {
                    //2 игра
                    strcpy(temp->name, Commands[j]);
                    strcpy(temp->opponent, Commands[i]);
                }
                p1 = rand() % 6;
                p2 = rand() % 6;
                if (p1 > p2)
                {
                    temp->ownerPoints = 3;
                    temp->oppPoints = 0;
                }
                else if (p1 == p2)
                {
                    temp->ownerPoints = 1;
                    temp->oppPoints = 1;
                }
                else
                {
                    temp->ownerPoints = 0;
                    temp->oppPoints = 3;
                }
                //Запись счета
                sprintf(temp->match, " %d : %d ", p1, p2);
                //Добавление записи
                tournament.Insert(temp);
            }
        }
}

int main()
{
    srand(time(0));
    const int N = 4;
    char Commands[4][20] = {
            "Arsenal",
            "Liverpool",
            "Lids United",
            "Manchester United"};
    //Игра
    Game(Commands, N);
    //Вывод результатов
    tournament.Print(tournament.GetRoot());
}
