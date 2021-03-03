#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include "visitor.hpp"

class Mult : public Base {
    public:
        Mult(Base* initVal, Base* multVal) : Base(), val1(initVal), val2(multVal) {}
        virtual double evaluate() {return val1 -> evaluate() * val2 -> evaluate(); }
        virtual std::string stringify() {
            return val1 -> stringify() + " * " + val2 -> stringify();
        }
  	 void accept(Visitor* visitor, int index) {          
		 if (index == 0) {                  
			 visitor->visit_mult_begin(this); }          
		 else if (index == 1) {                  
			 visitor->visit_mult_middle(this); }          
		 else if (index == 2) { 
			 visitor->visit_mult_end(this); }  
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
	void accept(Visitor* visitor, int index) {          
		 if (index == 0) {                  
			 visitor->visit_mult_begin(this); }          
		 else if (index == 1) {                  
			 visitor->visit_mult_middle(this); }          
		 else if (index == 2) { 
			 visitor->visit_mult_end(this); }  
	 }
    private:
        Base* val1;
        Base* val2;
};

#endif
