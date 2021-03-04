#include "visitor.hpp" 
//#include "base.hpp" 
#include "add.hpp" 
#include "sub.hpp" 
#include "div.hpp" 
#include "mult.hpp" 
#include "op.hpp" 
#include "pow.hpp" 
#include "rand.hpp"  
//#include "iterator.cpp" 
#include <sstream>  
#include <vector>
//#include <stack>
//#include <queue>
#include <iostream>
#include <string>
using namespace std;


class VisitMathML: public Visitor{ 	
private: 	
//Base* val1; 	
//Base* val2; 	
public: 	
  //std::string expr = "$"; 
  string theory= "";
  vector<string> num;
  vector<string> sign;
  vector<string> sign2;
  int space= 0;
  int signSpace= 0;


virtual void visit_op(Op* node){ 		
  string cheese= "";
  cheese += "<cn>"; 		
  ostringstream s;                 
  s << node->getVal();                 
  cheese += s.str(); 		
  cheese += "</cn>"; 	
  num.push_back(cheese);
  space++;
}  

virtual void visit_rand(Rand* node){ 		
  string beans= "";
  beans += "<cn>"; 		
  ostringstream s;                 
  s << node->getVal();                 
  beans += s.str(); 		
  beans += "</cn>"; 	
  num.push_back(beans);
  space++;	
} 	

//Implementing functions for nodes with no children 	 	
virtual void visit_add_begin(Add* node){ sign.push_back("<times/>");
  space++;
  signSpace++;
}
virtual void visit_add_middle(Add* node){ 
  //sign.push_back(" ");
  space++;
  
 }         
virtual void visit_add_end(Add* node){ 
  //sign.push_back(" ");
  space++;
  
 } 

virtual void visit_sub_begin(Sub* node){ sign.push_back("<minus/>");
  space++;
  signSpace++;
} 
virtual void visit_sub_middle(Sub* node){ 
  //sign.push_back(" ");
  space++;
  
 }       
virtual void visit_sub_end(Sub* node){ 
  //sign.push_back(" ");
  space++;
  
 }     

virtual void visit_mult_begin(Mult* node){  sign.push_back("<plus/>");
  space++;
  signSpace++;
 }
virtual void visit_mult_middle(Mult* node){ 
  //sign.push_back(" ");
  space++;
  
 }  
virtual void visit_mult_end(Mult* node){  
  //sign.push_back(" ");
  space++;
  
 }     

virtual void visit_div_begin(Div* node){  sign.push_back("<divide/>");
  space++;
  signSpace++;
 } 
virtual void visit_div_middle(Div* node){ 
  //sign.push_back(" ");
  space++;
  
 }      
virtual void visit_div_end(Div* node){ 
  //sign.push_back(" ");
  space++;
  
 }     

virtual void visit_pow_begin(Pow* node){  sign.push_back("<power/>");
  space++;
  signSpace++;
 }  
virtual void visit_pow_middle(Pow* node){ 
  //sign.push_back(" ");
  space++;
  
 }       
virtual void visit_pow_end(Pow* node){ 
  //sign.push_back(" ");
  space++;
  
 } 

std::string PrintFunction(Base* ptr){ 		
  auto * itr = new Iterator(ptr); 

  while(!itr->is_done()){ 			
    itr->current_node()->accept(this, itr->current_index());	
    itr->next();         
  }         

   for(int i= sign.size()-1; i>=0 ; i-- ){
    sign2.push_back(sign[i]); 
  }
 
  cout<<"    <math>"<<endl;
  cout<<"      <apply>"<<endl;
  cout<<"        "<<sign2[0]<<endl;
  cout<<"        "<<num[0]<<endl;
  cout<<"        "<<num[1]<<endl;

  for(int i= 1; i<sign2.size() ; i++ ){
    cout<<"        "<<sign2[i]<<endl;
    if( (i+1) < num.size()){
      cout<<"        "<<num[i+1]<<endl;
    }
  }
  
  cout<<"      </apply>"<<endl;
  cout<<"    </math>"<<endl;

  return this->theory; 	
} 


VisitMathML(){} 	
isitMathML(){} 
};
