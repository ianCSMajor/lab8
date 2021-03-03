#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "sstream"
#include <math.h>
#include <stdlib.h>
#include "visitor.hpp"
using namespace std;

class Op : public Base {
    public:
        Op(double value) : Base(), val(value) { }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
        virtual int number_of_children() {return 0;}
        virtual Base* get_child(int i){return nullptr;}
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
	  virtual int number_of_children() {
 		  int temp = 0;
 		  if (val1 != nullptr) { temp++; }
 		  if (val2 != nullptr) { temp++; }
 		  return temp;
	  }
	  virtual Base* get_child(int i){
      // 1 and 2 have been changed to 0 and 1
		  if(i==0){
			  return val1;	
		  }else if(i==1){
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
	  virtual int number_of_children() {
      int temp = 0;
      if (val1 != nullptr) { temp++; }
      if (val2 != nullptr) { temp++; }
      return temp;
    }
    virtual Base* get_child(int i){
      if(i==0){
        return val1;
      }else if(i==1){
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
	      virtual int number_of_children() {
          int temp = 0;
          if (val1 != nullptr) { temp++; }
          if (val2 != nullptr) { temp++; }
          return temp;
        }
        virtual Base* get_child(int i){
          if(i==0){
                return val1;
          }else if(i==1){
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
		    // return NULL;
        return 0.0;
	    }
	    return val1 -> evaluate() / val2 -> evaluate();
	  }
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
      if(i==0){
        return val1;
      }else if(i==1){
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
	  virtual int number_of_children() {
                int temp = 0;
                if (base != nullptr) { temp++; }
                if (exp != nullptr) { temp++; }
                return temp;
        }
    virtual Base* get_child(int i){
      if(i==0){
              return base;
      }else if(i==1){
              return exp;
      }else{
              return nullptr;
      }
    }
  private:
	  Base* base;
	  Base* exp;
};


class Rand : public Base {
  public:
    Rand(): Base(), val(rand() % 100) {}
    virtual double evaluate() { return val; }
    virtual std::string stringify() { return std::to_string(val); }
	  virtual int number_of_children() {return 0;}
    virtual Base* get_child(int i){return nullptr;
    }
  private:
	  double val;
};



#endif //__OP_HPP__
