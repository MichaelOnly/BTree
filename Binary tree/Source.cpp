/*������� ������:

1.� �������� �������� ������ ���������� ����� ��� ������� � ���������� �� ��������:
�) �������� �����, ����������.


������ �����:

(�������,(�����_���������),(������_���������))


������� ������� ����� ������:
   (A,(B,0,0),(C,0,0))
            A
           / \
          B   C
          
   (�,(B,(C,0,0),(D,0,0)),(E,0,0))
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

btree* BuildTree()  //������� ����� ������
{
   btree* d; //��������� �� ������ ������
   char sym; //������� ������
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

void NLR(btree* d, int * k)          //���������� ������� ������ ������ � ������� ����� ��������
{
   if (d)
   {
      if (!(d->left) && !(d->right)) //��������� �������� ��������
      {
         cout << d->el << ' ';
         (*k)++;
      }
      else 
      {
         NLR(d->left,k);    //����� ������ ���������
         NLR(d->right,k);   //����� ������� ���������
      }
   }

}

btree* DelTree(btree* d)  //���-�� � ���� ������� ��������, �� � �� �������, ���. ��������� ����� �� �������� ���������
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

   cout << "������� ������:" << endl;
   d = BuildTree();

   NLR(d, &k);

   cout << endl << "���������� ������� � ������: " << k;

   d = DelTree(d);
   _getch();
}