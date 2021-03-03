class VisitorLaTeX: public Visitor{  
	private:
	//Base* val1;
	//Base* val2;
	public:
	std::string expr = "$";
	
	
	virtual void visit_op(Op* node){
		expr += "{";
		std::ostringstream s;
                s << node->val;
                exp += s.str();
		expr += "}$";
	}
        virtual void visit_rand(Rand* node){
		expr += "{";
		std::ostringstream s;
                s << node->val;
                exp += s.str();
		expr += "}$";
	}
	//Implementing functions for nodes with no children
	
	virtual void visit_add_begin(Add* node){
		expr += "{(";
	}
        virtual void visit_add_middle(Add* node){
		expr += "+";
	}
        virtual void visit_add_end(Add* node){
		expr += ")}";
	}
        virtual void visit_sub_begin(Sub* node){
		expr += "{(";
	}
        virtual void visit_sub_middle(Sub* node){
		expr += "-";
	}
        virtual void visit_sub_end(Sub* node){
		expr += ")}";
	}
        virtual void visit_mult_begin(Mult* node){
		expr += "{(";
	}
        virtual void visit_mult_middle(Mult* node){
		expr += "\\cdot";
	}
        virtual void visit_mult_end(Mult* node){
		expr += ")}";
	}
        virtual void visit_div_begin(Div* node){
		expr += "{(";
	}
        virtual void visit_div_middle(Div* node){
		expr += "\frac";
	}
        virtual void visit_div_end(Div* node){
		expr += ")}";
	}
        virtual void visit_pow_begin(Power* node){
		expr += "{(";
	}
        virtual void visit_pow_middle(Power* node){
		expr += "^";
	}
        virtual void visit_pow_end(Power* node){
		expr += ")}";
	}
	std::string PrintFunction(Base* ptr){
		auto * itr = new Iterator(ptr);
		
		while(!(itr->is_done)){
			itr->current_node()->accept(this, itr->current_index());
                	itr->next();
        }
        return this->expr;
	}
			
	
	VisitorLaTeX(Base* initialVal, Base* subVal): Base(), val1(initialVal), val2(subVal) {}
	~VisitorLaTeX();
};

