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
#include <locale>

using namespace std;

struct btree            
{
   char el;
   btree *right, *left;
};

/*btree* BuildTree()  //������� ����� ������
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

void NLR(btree* d, int &k)          //���������� ������� ������ ������ � ������� ����� ��������
{
   if (d)
   {
      if (!(d->left) && !(d->right)) //��������� �������� ��������
      {
         cout << d->el << ' ';
         k++;
      }
      else 
      {
         NLR(d->left,k);    //����� ������ ���������
         NLR(d->right,k);   //����� ������� ���������
      }
   }

}

btree* DelTree(btree* d)  //������� �������� ������, ������������� ����������
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

   cout << "������� ������:" << endl;
   d = BuildTree();

   NLR(d, k);

   cout << endl << "���������� ������� � ������: " << k;

   d = DelTree(d);
   getchar();
}