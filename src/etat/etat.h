#if !defined ( ETAT_H )
#define ETAT_H
	class Etat {
		public: 	
			Etat(string name);
			virtual ~Etat();
			void print() const;
			virtual bool transition(Automate & automate, Symbole * s ) = 0;
		protected: 
			string name;
	};
#endif
