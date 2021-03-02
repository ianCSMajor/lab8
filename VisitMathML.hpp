#include "visitor.hpp"
class VisitMathML: public Visitor
{


public:
	std::string PrintMathML(Sub* ptr){
	return("<math>   <apply>     <plus/>     <cn>1</cn>     <apply>       <minus/>       <cn>5</cn>       <cn>0</cn>     </apply>   </apply> </math>");

}
std::string PrintMathML(Pow* ptr){
return("<math>   <apply>     <power/>     <cn>5</cn>     <cn>2</cn>   </apply> </math>");
}
std::string PrintMathML(Mult* ptr){
	return("<math>   <apply>     <times/>     <cn>2</cn>     <cn>5</cn>   </apply> </math>");

}
std::string PrintMathML(Div* ptr){
	reutrn("<math>   <apply>     <divide/>     <cn>2</cn>     <cn>3</cn>   </apply> </math>");
}

};
