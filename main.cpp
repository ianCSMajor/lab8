#include <iostream>

#include "base.hpp"
#include "sub.hpp"
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
  // Base* three = new Op(3);
  // Base* seven = new Op(7);
  // Base* four = new Op(4);
  // Base* two = new Op(2);
  // Base* mult = new Mult(seven, four);
  // Base* add = new Add(three, mult);
  // Base* minus = new Sub(add, two);


  Base* three= new Op(3);
  Base* seven= new Op(7);
  Base* minus= new Sub(seven, three);
 
  cout<< minus->stringify() << " = " << minus->evaluate() << std::endl;


  Iterator i = Iterator(minus);
  do{
    cout<<"current index:"<<i.current_index()<<endl;
    cout<<"current node: "<<i.current_node()->evaluate()<<endl;
    i.next();
    
  }while(!(i.is_done()));

 Base * two = new Op(2);
 Base * six = new Op(6);
 cout << endl << "-------------------LATEX--------------------:" << endl;
  VisitorLaTeX* visit = new VisitorLaTeX();
   cout << visit->PrintFunction(minus);
   cout << endl;
delete three;
delete seven;
delete minus;
delete visit;

  return 0;
}
