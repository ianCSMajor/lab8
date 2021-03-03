#include <iostream>

#include "base.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "VisitorLaTeX.hpp"
#include "iterator.hpp"
using namespace std;

int main() {
  // This is a very basic main, and being able to correctly execute this main
  // does not constitute a completed lab. Make sure you write unit tests for
  // all the classes that you create (and can be instantiated) in this lab
    //the expression:  Sub( Add( Op(3), Mult(Op(7),Op(4)) ), Op(2)  )
  // or 7x4+3-2 = 29
   VisitorLaTeX* visit = new VisitorLaTeX();
   Base* three = new Op(3);
   Base* seven = new Op(7);
   Base* four = new Op(4);
   Base* two = new Op(2);
   Base* mult = new Mult(seven, four);
   Base* add = new Add(three, mult);
   Base* minus = new Sub(add, two);
   //cout << visit->PrintFunction(mult);
   //cout << visit->PrintFunction(add);
   //cout << endl;
   //cout << visit->PrintFunction(minus);
   //cout << endl;	
  //Base* three= new Op(3);
  //Base* seven= new Op(7);
  //Base * randNum = new Rand();
  //Base* minus= new Sub(seven, three);
 
  cout<< minus->stringify() << " = " << minus->evaluate() << std::endl;


  Iterator i = Iterator(minus);
  do{
    cout<<"current index:"<<i.current_index()<<endl;
    cout<<"current node: "<<i.current_node()->evaluate()<<endl;
    i.next();
    
  }while(!(i.is_done()));

 //Base * two = new Op(2);
 //Base * six = new Op(6);
 //Base * add = new Add(two, six);
 cout << endl << "-------------------LATEX--------------------:" << endl;
cout << endl;    cout << visit->PrintFunction(minus);    cout << endl;
  //VisitorLaTeX* visit = new VisitorLaTeX();
   //cout << visit->PrintFunction(minus);
   cout << endl;
   //VisitorLaTeX* visit2 = new VisitorLaTeX();
   //cout << visit2->PrintFunction(add);

delete visit;
delete three;
delete seven;
delete minus;
delete four;
delete two;
delete mult;
delete add;
//delete visit;
//delete visit2;

  return 0;
}
