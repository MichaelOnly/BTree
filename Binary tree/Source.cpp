/*Условие задачи:

1.В заданном бинарном дереве подсчитать число его листьев и напечатать их значения:
г) реализуя обход, рекурсивно.


Формат ввода:

(вершина,(левое_поддерево),(правое_поддерево))


Примеры формата ввода дерева:
   (A,(B,0,0),(C,0,0))
            A
           / \
          B   C
          
   (А,(B,(C,0,0),(D,0,0)),(E,0,0))
               A
              / \
             B   E
            / \
           C   D*/



#include <iostream>
#include <locale>
#include <conio.h>

using namespace std;

struct btree            
{
   char el;
   btree *right, *left;
};

btree* BuildTree()  //Функция ввода дерева
{
   btree* tree; //Указатель на корень дерева
   char sym; //Текущий символ
   cin >> sym;
   switch (sym)
   {
      case '(': 
      {
         tree = new btree;
         cin >> tree->el;
         tree->left = BuildTree();
         tree->right = BuildTree();
         cin >> sym;
         return tree;
      }
      case '0': return NULL;
      case ',': return BuildTree();
   }
}

void NLR(btree* tree, int& leafCount)      //Реализация прямого обхода дерева в глубину через рекурсию
{
   if (tree) {
      if (tree->left == NULL && tree->right == NULL) {
         cout << tree->el << ' ';
         leafCount++;
         return;                     //Необязательно проверять tree->left и tree->right если это лист
      }
      NLR(tree->left, leafCount);    //Обход левого поддерева
      NLR(tree->right, leafCount);   //Обход правого поддерева
   }
}

void DeleteTree(btree* tree)  //Функция удаления дерева, реализованная рекурсивно
{
   if (tree)
   {
      DeleteTree(tree->left);
      DeleteTree(tree->right);
      delete tree;
   }
}

int main()
{
   setlocale(LC_CTYPE, "Rus");

   btree* tree;
   int leafCount = 0;

   cout << "Введите дерево:" << endl;
   tree = BuildTree();

   NLR(tree, leafCount);

   cout << endl << "Количество листьев в дереве: " << leafCount;

   DeleteTree(tree);
   _getch();
   return 0;
}