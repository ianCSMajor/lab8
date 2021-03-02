#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "base.hpp"
#include <math.h>

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) = 0;
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;
};

class Op : public Base {
    public:
        Op(double value) : Base(), val(value) { }
        virtual double evaluate() { return val; }
	 void accept(Visitor* visitor, int index) {            
		 visitor->visit_op(this)
		 }        
	 }
        virtual std::string stringify() { return std::to_string(val); }
    private:
	double val;
};

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
    private:
	double val;
};
class Add : public Base {
    public:
	Add(Base* initialVal, Base* addVal): Base(), val1(initialVal), val2(addVal) {}
	virtual double evaluate() {return val1 -> evaluate() + val2 -> evaluate();}
	virtual std::string stringify() {
	    return val1 -> stringify() + " + " + val2 -> stringify();
	}
	  void accept(Visitor* visitor, int index) {          
		if (index == 0) {                  
			visitor->visit_add_begin(this); }          
		else if (index == 1) {                  
			visitor->visit_add_middle(this); }          
		else if (index == 2) { visitor->visit_add_end(this); }  
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

    private:
        Base* val1;
        Base* val2;
};
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
#endif //__VISITOR_HPP__
