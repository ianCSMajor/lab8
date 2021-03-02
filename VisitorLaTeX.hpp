class VisitorLaTeX{  
	std::string PrintLaTex(Pow* ptr) {             
		return ("${({" + val1 -> stringify() + "}^{" + val2 -> stringify() + "})}$";         
} 
std::string PrintLaTex(Div* ptr) {             
	return ("${\frac{" + val1 -> stringify() + "}{" + val2 -> stringify() + "}}$";         
} 
std::string PrintLaTex(Mult* ptr) {             
	return ("${({" + val1 -> stringify() + "}^{" + val2 -> stringify() + "})}$";         }  };
