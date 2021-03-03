#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double value) : Base(), val(value) { }
        virtual double evaluate() { return val; }
	 void accept(Visitor* visitor, int index) {            
		 visitor->visit_op(Op* node)
		 }        
	 }
        virtual std::string stringify() { return std::to_string(val); }
	virtual int number_of_children() {
                return 0;
        }
        virtual Base* get_child(int i){
                return nullptr;
        }
	void accept(Visitor* visitor, int index) {            
		 visitor->visit_op(this);
	}        
    private:
	double val;
};

#endif //__OP_HPP__

