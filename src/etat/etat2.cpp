#include "etat2.h"
#include "etat0.h"
#include "etat1.h"
#include "etat3.h"
#include "etat4.h"
#include "etat5.h"
#include "etat6.h"
#include "../config.h"


Etat2::Etat2(string pName) : Etat(pName){}
Etat2::Etat2(){}
Etat2::~Etat2(){}

bool Etat2::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case LI :
			automate.decalage(s, new Etat3);
			break;
		case D :
			automate.decalage(s, new Etat4);
			break;
		case ct :
			automate.decalage(s, new Etat5);
			break;
		case va :
			automate.decalage(s, new Etat6);
			break;
		case id : 
		case r :
		case w :
		case dollar :
			//Reduction r11 : Li -> .
			break;
		default : break;
	}
	return false;
}
