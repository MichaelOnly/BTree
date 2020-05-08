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

using namespace std;

struct btree            
{
   char el;
   btree *right, *left;
};

/*btree* BuildTree()  //Функция ввода дерева
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

}*/

btree* BuildTree()  
{
   btree* d; 
   char sym, sym2;
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
         return d;
      }
      case ',':
      {
         cin >> sym2;
         switch (sym2)
         {
         case ',':
         {
            return NULL;
         }
         case ')':
         {
            return NULL;
         }
         case '(':
         {
            sym = sym2;
         }
         default:
         {
            sym = sym2;
         }
         }
      }
      case ')':
      {
         return NULL;
      }
      default:
      {
         cin >> sym2;
         if (sym2 == ',')
         {
            d = new btree;
            d->el = sym;
            d->left = NULL;
            d->right = NULL;
            return d;
         }
         else
         {
            d = new btree;
            d->el=sym;
            d->left = NULL;
            d->right = NULL;
            return d;
         }
      }
   }
   
   }

void NLR(btree* d, int &k)          //Реализация прямого обхода дерева в глубину через рекурсию
{
   if (d)
   {
      if (!(d->left) && !(d->right)) //Обработка текущего элемента
      {
         cout << d->el << ' ';
         k++;
      }
      else 
      {
         NLR(d->left,k);    //Обход левого поддерева
         NLR(d->right,k);   //Обход правого поддерева
      }
   }

}

btree* DelTree(btree* d)  //Функция удаления дерева, реализованная рекурсивно
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
   setlocale(LC_CTYPE, "Rus");

   btree* d;
   int k = 0;

   cout << "Введите дерево:" << endl;
   d = BuildTree();

   NLR(d, k);

   cout << endl << "Количество листьев в дереве: " << k;

   d = DelTree(d);
   getchar();
}