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
  vector<string> q;
  int donothing= 0;


virtual void visit_op(Op* node){ 		
  string cheese= "";
  cheese += "<cn>"; 		
  ostringstream s;                 
  s << node->getVal();                 
  cheese += s.str(); 		
  cheese += "</cn>"; 	
  q.push_back(cheese);
}  

virtual void visit_rand(Rand* node){ 		
  string beans= "";
  beans += "<cn>"; 		
  ostringstream s;                 
  s << node->getVal();                 
  beans += s.str(); 		
  beans += "</cn>"; 	
  q.push_back(beans);	
} 	

//Implementing functions for nodes with no children 	 	
virtual void visit_add_begin(Add* node){ q.push_back("<plus/>"); }
virtual void visit_add_middle(Add* node){ q.push_back(" "); }         
virtual void visit_add_end(Add* node){ q.push_back(" "); } 

virtual void visit_sub_begin(Sub* node){ q.push_back("<minus/>"); }    
virtual void visit_sub_middle(Sub* node){ q.push_back(" "); }       
virtual void visit_sub_end(Sub* node){ q.push_back(" "); }     

virtual void visit_mult_begin(Mult* node){  q.push_back("<times/>"); } 
virtual void visit_mult_middle(Mult* node){ q.push_back(" "); }  
virtual void visit_mult_end(Mult* node){  q.push_back(" "); }     

virtual void visit_div_begin(Div* node){  q.push_back("<divide/>"); }  
virtual void visit_div_middle(Div* node){ q.push_back(" "); }      
virtual void visit_div_end(Div* node){ q.push_back(" "); }     

virtual void visit_pow_begin(Pow* node){  q.push_back("<power/>"); }   
virtual void visit_pow_middle(Pow* node){ q.push_back(" "); }       
virtual void visit_pow_end(Pow* node){ q.push_back(" "); } 

std::string PrintFunction(Base* ptr){ 		
  auto * itr = new Iterator(ptr); 

  while(!itr->is_done()){ 			
    itr->current_node()->accept(this, itr->current_index());	
    itr->next();         
  }         

  cout<<"    <math>"<<endl;
  cout<<"      <apply>"<<endl;
  for(string s : q){
    if(s != " ")
      cout<<"       "<<s<<endl;
  }
  cout<<"      </apply>"<<endl;
  cout<<"    </math>"<<endl;

  return this->theory; 	
} 


VisitMathML(){} 	
isitMathML(){} 
};
