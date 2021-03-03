class VisitorLaTeX: public Visitor{  
	private:
	Base* val1;
	Base* val2;
	string start = "${";
	string end = "}$";
	public:
	
	//Implementing functions for nodes with no children
	
	virtual void visit_op(Op* node){
		cout << start << node->val << end << endl;
	}
	virtual void visit_rand(Rand* node){
		cout << start << node->val << end << endl;	
	}
	virtual void visit_add_begin(Add* node){
		cout << start << "({";
	};
        virtual void visit_add_middle(Add* node){
		cout << "}+{";	
	}
        virtual void visit_add_end(Add* node){
		cout << "})" << end;	
	}
        virtual void visit_sub_begin(Sub* node){
		cout << start << "({";
	}
        virtual void visit_sub_middle(Sub* node){
		cout << "}-{";
	}
        virtual void visit_sub_end(Sub* node){
		cout << "})" << end;
	}
        virtual void visit_mult_begin(Mult* node){
		cout << start << "({";	
	}
        virtual void visit_mult_middle(Mult* node){
		cout << "}\cdot{";	
	}
        virtual void visit_mult_end(Mult* node){
		cout << "})" << end;
	}
        virtual void visit_div_begin(Div* node)
	{
		cout << start << "\frac" << "{";	
	}
        virtual void visit_div_middle(Div* node){
		cout << "}{";	
	}
        virtual void visit_div_end(Div* node){
		cout << "}" << end;
	}
        virtual void visit_pow_begin(Pow* node)
	{
		cout << start << "({";		
	}
        virtual void visit_pow_middle(Pow* node){
		cout << "}\cdot{";
	}
        virtual void visit_pow_end(Pow* node){
		cout << "})" << end;	
	}
	
	VisitorLaTeX(Base* initialVal, Base* subVal): Base(), val1(initialVal), val2(subVal) {}
	~VisitorLaTeX();
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
