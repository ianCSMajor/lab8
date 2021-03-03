#ifndef __RAND_HPP__
#define __RAND_HPP__
#include <stdlib.h>

#include "base.hpp"
#include "visitor.hpp"

class Rand : public Base {
    public:
        Rand(): Base(), val(rand() % 100) {}
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
	virtual int number_of_children() {
                return 0;
        }
	 void accept(Visitor* visitor, int index) {   
		 visitor->visit_rand(this)
		 } 
        virtual Base* get_child(int i){
                        return nullptr;
        }
	void accept(Visitor* visitor, int index) {   
		 visitor->visit_rand(this);
	} 
    private:
	double val;
};
#endif

