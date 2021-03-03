#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <math.h>

class Pow : public Base {
    public:
	Pow(Base* baseVal, Base* expVal) : Base(), base(baseVal), exp(expVal) {}
	virtual double evaluate() {pow(base -> evaluate(), exp -> evaluate());}
	virtual std::string stringify() {
		return base -> stringify() + " ** " + exp -> stringify();
	}
         void accept(Visitor* visitor, int index) {          
		 if (index == 0) {                  
			 visitor->visit_pow_begin(this); }          
		 else if (index == 1) {                  
			 visitor->visit_pow_middle(this); }          
		 else if (index == 2) { 
			 visitor->visit_pow_end(this); }  
	 }
	virtual int number_of_children() {
                int temp = 0;
                if (base != nullptr) { temp++; }
                if (exp != nullptr) { temp++; }
                return temp;
        }
        virtual Base* get_child(int i){
                if(i==1){
                        return base;
                }else if(i==2){
                        return exp;
                }else{
                        return nullptr;
                }
        }
    private:
	Base* base;
	Base* exp;
};

#endif

