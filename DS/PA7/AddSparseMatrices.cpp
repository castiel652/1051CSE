#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

struct entryNode
{
   int row;
   int col;
   int value;
};

enum tagfield
{
   head, entry
};

struct MatrixNode
{
   MatrixNode *down;
   MatrixNode *right;
   tagfield tag;
   union
   {
      MatrixNode *next;
      entryNode entry;
   } u;
};

class SparseMatrix
{
   // print out sparseMatrix in row major form
   friend ostream &operator<<( ostream &output, const SparseMatrix &sparseMatrix );
public:
   SparseMatrix(); // default constructor with empty body

   SparseMatrix( const SparseMatrix &matrixToCopy ); // copy constructor

   ~SparseMatrix(); // destructor in which the matrix is erased

   const SparseMatrix &operator=( const SparseMatrix &op2 );

   void read(); // read in a matrix and set up its linked representation

   SparseMatrix operator+( SparseMatrix &op2 ); // Returns the sum of two sparse matrices

   void printColumnMajor(); // print out the matrix in column major form

   void erase(); // erase the matrix
private:
   MatrixNode *node; // a pointer to the header node for the list of header nodes
};

#endif

SparseMatrix::SparseMatrix()
   : node( 0 )
{
}

SparseMatrix::SparseMatrix( const SparseMatrix &matrixToCopy ); // copy constructor
{
        if(matrixToCopy->node == NULL) /* In case mTC is empty */
                node = NULL;
        else {
                node = new MatrixNode;
                node->tag = matrixToCopy->node->tag;
                node->u.entry.row = matrixToCopy->node->u.entry.row;
                node->u.entry.col = matrixToCopy->node->u.entry.col;

                int numHeads = (u.entry.col > u.entry.row) ? u.entry.col : u.entry.row; /* determine the numbers of head node */
                MatrixNode *temp;
                for(int i = 0; i < numHeads; ++i) {
                        temp = new MatrixNode;
                }
        }
}

SparseMatrix::~SparseMatrix()
{
   erase();
}

void SparseMatrix::printColumnMajor()
{  // print out the matrix in column major form
   cout << node->u.entry.row << " ";
   cout << node->u.entry.col << " ";
   cout << node->u.entry.value << endl;

   for( MatrixNode *head = node->right; head != node; head = head->u.next )
      for( MatrixNode *temp = head->down; temp != head; temp = temp->down )
      {
         cout << temp->u.entry.row << " ";
         cout << temp->u.entry.col << " ";
         cout << temp->u.entry.value << endl;
      }
}

ostream &operator<<( ostream &output, const SparseMatrix &sparseMatrix )
{  // print out the matrix in row major form
   cout << sparseMatrix.node->u.entry.row << " ";
   cout << sparseMatrix.node->u.entry.col << " ";
   cout << sparseMatrix.node->u.entry.value << endl;

   MatrixNode *head = sparseMatrix.node;
   for( head = head->right; head != sparseMatrix.node; head = head->u.next )
      for( MatrixNode *temp = head->right; temp != head; temp = temp->right )
      {
         cout << temp->u.entry.row << " ";
         cout << temp->u.entry.col << " ";
         cout << temp->u.entry.value << endl;
      }

   return output; // enables cout << x << y;
}

int main()
{
   SparseMatrix addend;
   SparseMatrix adder;
   addend.read();
   adder.read();
   SparseMatrix sum;
   sum = addend + adder;
   cout << sum << endl;
   sum.printColumnMajor();
}
