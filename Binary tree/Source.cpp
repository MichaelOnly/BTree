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
#include <locale.h>
#include <conio.h>

using namespace std;

struct btree            
{
   char el;
   btree *right, *left;
};

btree* BuildTree()  //Функция ввода дерева
{
   btree* d; //Указатель на корень дерева
   char sym; //Текущий символ
   cin >> sym;
   switch (sym)
   {
      case '(': 
      {
         d = new btree;
         cin >> sym;
         d->el = sym;
         d->left = BuildTree();
         d->right = BuildTree();
         cin >> sym;
         return d;
      }
      case '0': return NULL;
      case ',': 
      {
         d = BuildTree();
         return d;
      }
   }

}

void NLR(btree* d, int * k)          //Реализация прямого обхода дерева в глубину через рекурсию
{
   if (d)
   {
      if (!(d->left) && !(d->right)) //Обработка текущего элемента
      {
         cout << d->el << ' ';
         (*k)++;
      }
      else 
      {
         NLR(d->left,k);    //Обход левого поддерева
         NLR(d->right,k);   //Обход правого поддерева
      }
   }

}

btree* DelTree(btree* d)  //Где-то в этой функции проблема, но я не понимаю, где. Остальное вроде всё работает правильно
{
   if (d)
   {
      d->left = DelTree(d->left);
      d->right = DelTree(d->right);
      delete d;
      return NULL;
   }
}

int main()
{
   setlocale(LC_ALL, "Rus");

   btree* d;
   int k = 0;

   cout << "Введите дерево:" << endl;
   d = BuildTree();

   NLR(d, &k);

   cout << endl << "Количество листьев в дереве: " << k;

   d = DelTree(d);
   _getch();
}