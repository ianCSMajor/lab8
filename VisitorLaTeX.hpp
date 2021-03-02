class VisitorLaTeX: public Visitor{  
	std::string PrintLaTex(Pow* ptr) {             
		return ("${({" + val1 -> stringify() + "}^{" + val2 -> stringify() + "})}$");         
} 
std::string PrintLaTex(Div* ptr) {             
	return ("${\frac{" + val1 -> stringify() + "}{" + val2 -> stringify() + "}}$");         
} 
std::string PrintLaTex(Mult* ptr) {             
	return ("${({" + val1 -> stringify() + "}\cdot{" + val2 -> stringify() + "})}$");         }  };
