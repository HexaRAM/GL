
class Expr: public Symbole { 
	public:
		Expr():Symbole(EXPR) {}
		virtual ~Expr() {}
		virtual double eval()

	
}