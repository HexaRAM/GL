#if !defined ( SYMBOLE_H )
#define SYMBOLE_H
	class Symbole {
	protected:
		int indent;
	public:
		Symbole(int id) : ident(id) {}
		virtual ~Symbole() {}
		void print();
		operator int() const { 
			return ident;
		}
	}#endif 