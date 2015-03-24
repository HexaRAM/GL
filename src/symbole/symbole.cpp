#include "symbole.h"

ostream& operator<<(ostream& os, const Symbole& dt){
	dt.print(os);
	return os;
}

/*void Symbole::print(ostream& os) const {
	//TODO
}*/

/*Symbole::ostream& operator<<(ostream& os, const Symbole& dt)
{
	int identifiant = dt;
    switch(identifiant){
	    case  pv :
	       os<<";";
	       break; //optional
	    case  ct :
	       os<<"const";
	       break; //optional
	  	case  va :
	       os<<"var";
	       break; //optional
	    case  v :
	       os<<",";
	       break; //optional
	    case  id :
	       os<<"";				//TODO
	       break; //optional
	    case  eg :
	       os<<"=";
	       break; //optional
	    case  num :
	       statement(s);		//TODO
	       break; //optional
	    case  af :
	       os<<":=";
	       break; //optional
	    case  r :
	       os<<"lire";
	       break; //optional
	    case  w :
	       os<<"ecrire";
	       break;
	    case  po :
	       os<<"(";
	       break;
	    case  pf :
	       os<<")";
	       break;
	    case  add :
	       os<<"+";
	       break;
	    case  moins :
	       os<<"-";
	       break;
	    case  fois :
	       os<<"*";
	       break;
	    case  divise :
	       os<<"/";
	       break;
	    case  dolar :
	       os<<"$";
	       break;
	    default : //Optional
	       statement(s);		//TODO
	}
    return os;
}*/