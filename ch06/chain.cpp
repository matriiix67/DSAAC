// test the class chain
#include<iostream>
#include "linearList.h"
#include "chain.h"

using namespace std;

int main()
{
   // test constructor
   linearList<double> *x = new chain<double>;
   chain<int> y, z;

   // test size
   cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << endl;

   // test empty
   if (x->empty()) cout << "x is empty" << endl;
   else cout << "x is not empty" << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;

   // test insert
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
}
