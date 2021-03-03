#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"

#include "iterator.hpp"
//#include "visitor.hpp"
#include "VisitorLaTeX.hpp"
#include "VisitMathML.hpp"
using namespace std;

int main() {
  // This is a very basic main, and being able to correctly execute this main
  // does not constitute a completed lab. Make sure you write unit tests for
  // all the classes that you create (and can be instantiated) in this lab
    //the expression:  Sub( Add( Op(3), Mult(Op(7),Op(4)) ), Op(2)  )
  // or 7x4+3-2 = 29
  Base* three = new Op(3);
  Base* seven = new Op(7);
  Base* four = new Op(4);
  Base* two = new Op(2);
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* minus = new Sub(add, two);
  cout<<"\n\n----------------Expression:-------------\n"<<endl;
  cout<< minus->stringify()<<" = "<<minus->evaluate() <<endl<<endl<<endl;

  //simplified tree
  // Base* three= new Op(3);
  // Base* seven= new Op(7);
  // Base* minus= new Sub(seven, three);
  // cout<< minus->stringify() << " = " << minus->evaluate() << std::endl;

  // //old iterator
  // Iterator i = Iterator(minus);
  // do{
  //   cout<<"current index:"<<i.current_index()<<endl;
  //   cout<<"current node: "<<i.current_node()->evaluate()<<endl;
  //   i.next();
  // }while(!(i.is_done()));
  
  cout<<"\n--------------MathML------------------\n"<<endl;
  VisitMathML* v= new VisitMathML;
    cout<<v->PrintFunction(minus);
    cout<<endl<<endl<<endl;

  cout <<"\n-----------------LATEX----------------\n" << endl;
  VisitorLaTeX* visit = new VisitorLaTeX();
   cout << visit->PrintFunction(minus);
   cout<<endl<<endl<<endl;
  



  return 0;
}
