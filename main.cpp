#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
using namespace std;

int main() {
  // This is a very basic main, and being able to correctly execute this main
  // does not constitute a completed lab. Make sure you write unit tests for
  // all the classes that you create (and can be instantiated) in this lab
  Base* three = new Op(3);
  Base* seven = new Op(7);
  Base* four = new Op(4);
  Base* two = new Op(2);
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* minus = new Sub(add, two);

  //the expression:  Sub( Add( Op(3), Mult(Op(7),Op(4)) ), Op(2)  )
  // or 7x4+3-2 = 29

  cout<< minus->stringify() << " = " << minus->evaluate() << std::endl;


  Iterator i = Iterator(minus);
  // cout<<"current index:"<<i.current_index()<<endl;
  // cout<<"current node: "<<i.current_node()->evaluate()<<endl;

  do{
    cout<<"current index:"<<i.current_index()<<endl;
    i.next();
    
    //cout<<"current node: "<<i.current_node()->evaluate()<<endl;
  }while(!(i.is_done()));



  return 0;
}
