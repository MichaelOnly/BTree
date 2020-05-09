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
#include <conio.h>

using namespace std;

struct btree            
{
   char el;
   btree *right, *left;
};

btree* BuildTree()  //������� ����� ������
{
   btree* tree; //��������� �� ������ ������
   char sym; //������� ������
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

void NLR(btree* tree, int &leafCount)      //���������� ������� ������ ������ � ������� ����� ��������
{
   if (tree != NULL)
   {
      NLR(tree->left, leafCount);    //����� ������ ���������
      NLR(tree->right, leafCount);   //����� ������� ���������

      cout << tree->el << ' ';
      leafCount++;
   }
}

void DeleteTree(btree* tree)  //������� �������� ������, ������������� ����������
{
   if (tree != NULL)
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

   cout << "������� ������:" << endl;
   tree = BuildTree();

   NLR(tree, leafCount);

   cout << endl << "���������� ������� � ������: " << leafCount;

   DeleteTree(tree);
   _getch();
}