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
   btree* d;
   char sym;
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

btree* DelTree(btree* d)
{
   if (d)
   {
      if (!d->left)
      {
         d->left = DelTree(d->left);
      }
      if (!d->right)
      {
         d->right = DelTree(d->right);
      }
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