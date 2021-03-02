#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base(), val(value) { }
        virtual double evaluate() { return val; }
	 void accept(Visitor* visitor, int index) {          
		 if (index == 0) {                  
			 visitor->visit_op(this); }          
		 else if (index == 1) {                  
			 visitor->visit_op(this); }          
	 }
        virtual std::string stringify() { return std::to_string(val); }
    private:
	double val;
};

#endif //__OP_HPP__

