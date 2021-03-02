#ifndef __RAND_HPP__
#define __RAND_HPP__
#include <stdlib.h>
#include "base.hpp"

class Rand : public Base {
    public:
        Rand(): Base(), val(rand() % 100) {}
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
	virtual int number_of_children() {
                return 0;
        }
        virtual Base* get_child(int i){
                        return nullptr;
        }
    private:
	double val;
};
#endif
