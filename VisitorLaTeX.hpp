class VisitorLaTeX: public Visitor{  
	private:
	Base* val1;
	Base* val2;
	public:
	VisitorLaTeX(Base* initialVal, Base* subVal): Base(), val1(initialVal), val2(subVal) {}
	
	std::string PrintLaTex(Pow* ptr) {             
			return ("${({" + val1 -> stringify() + "}^{" + val2 -> stringify() + "})}$");         
	} 
	
	std::string PrintLaTex(Div* ptr) {             
		return ("${\frac{" + val1 -> stringify() + "}{" + val2 -> stringify() + "}}$");         
	} 
	
	std::string PrintLaTex(Sub* ptr) {             
		return ("${({" + val1 -> stringify() + "}-{" + val2 -> stringify() + "})}$");         
	} 
	
	std::string PrintLaTex(Add* ptr) {             
		return ("${({" + val1 -> stringify() + "}+{" + val2 -> stringify() + "})}$");         
	} 
	
	std::string PrintLaTex(Mult* ptr) {             
		return ("${({" + val1 -> stringify() + "}\cdot{" + val2 -> stringify() + "})}$");         }  };
