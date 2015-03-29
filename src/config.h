#ifndef H_CONFIG
#define H_CONFIG

//#define DEBUG // comment to remove debug mode

enum OPTIONS {
    ALL, CHECKED, AFFICHAGE, ANALYSE, OPTIMISATION, EXECUTION
};

enum ID_SYMBOLE{
	P = 0,
	LD = 1,
	D = 2,
	C = 3,
	V = 4,
	LI = 5,
	I = 6,
	E= 7,
	T = 8,
	F = 9,
	OA = 10,			//symbole operation addition
	OM = 11,			//symbole operation multiplication
	
	pv = 100,			//symbole ;
	ct = 101,			//symbole const
	va = 102,			//symbole var
	v = 103,			//symbole ,
	id = 104,			//symbole identificateur
	eg = 105,			//symbole =
	num = 106,			//symbole numerique
	af = 107,			//symbole :=
	r = 108,			//symbole lire
	w = 109,			//symbole ecrire
	po = 110,			//symbole (
	pf = 111,			//symbole )
	add = 112,			//symbole +
	moins = 113,		//symbole -
	fois = 114,			//symbole *
	divise = 115,		//symbole /
	dollar = 116,		//symbole $
	unknown = 1000
};
#endif
