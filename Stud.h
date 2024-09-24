#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "MyLib.h"

struct Stud {
	std::string vardas, pavarde;
	vector <int> nd;
	int egz;
	double galutinisVid, galutinisMed;
};

void input(Stud& Lok);
double skaiciuotiNdVid(const vector <int>& nd); //const uztrikrina, kad elementai nebus keiciami
double skaiciuotiNdMed(vector <int>& nd); //elementus reikes surikiuoti
void skaiciuotiGalutiniBala(Stud& Lok);
void output(Stud Lok);
void clean(Stud& Lok);

#endif // STUD_H_INCLUDED

