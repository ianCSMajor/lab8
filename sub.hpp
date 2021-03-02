#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Sub : public Base {
    public:
	Sub(Base* initialVal, Base* subVal): Base(), val1(initialVal), val2(subVal) {}
	virtual double evaluate() {return val1 -> evaluate() - val2 -> evaluate();}
	virtual std::string stringify() {
	    return val1 -> stringify() + " - " + val2 -> stringify();
	}

	void accept(Visitor* visitor, int index) {     
		if (index == 0) { 
			visitor->visit_sub_begin(this); }     
		else if (index == 1) { 
			visitor->visit_sub_middle(this); }     
		else if (index == 2) { 
			visitor->visit_sub_end(this); } 
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
