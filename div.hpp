#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Div : public Base {
    public:
	Div(Base* initVal, Base* divVal) : Base(), val1(initVal), val2(divVal) {}
	virtual double evaluate() {
	    if(val2 -> evaluate() == 0) {
		return NULL;
	    }
	    return val1 -> evaluate() / val2 -> evaluate();
	}
	 void accept(Visitor* visitor, int index) {          
		 if (index == 0) {                  
			 visitor->visit_div_begin(this); }          
		 else if (index == 1) {                  
			 visitor->visit_div_middle(this); }          
		 else if (index == 2) { 
			 visitor->visit_div_end(this); }  }
	virtual std::string stringify() {
		return val1 -> stringify() + " / " + val2 -> stringify();
	}
	virtual int number_of_children() {
                int temp = 0;
                if (val1 != nullptr) { temp++; }
                if (val2 != nullptr) { temp++; }
                return temp;
        }
        virtual Base* get_child(int i){
                if(i==1){
                        return val1;
                }else if(i==2){
                        return val2;
                }else{
                        return nullptr;
                }
        }
    private:
	Base* val1;
	Base* val2;
};

#endif
