#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "MyLib.h"

struct Stud {
	string vardas, pavarde;
	vector <int> nd;
	int egz;
	double galutinisVid, galutinisMed;
};

void input(Stud& Lok);
void readStudTxt(const string& failoVardas, vector <Stud>& studentai);
double skaiciuotiNdVid(const vector <int>& nd); //const uztrikrina, kad elementai nebus keiciami
double skaiciuotiNdMed(vector <int>& nd); //elementus reikes surikiuoti
void skaiciuotiGalutiniBala(Stud& Lok);
void outputVid(Stud Lok);
void outputMed(Stud Lok);
void clean(Stud& Lok);
//void outputTxt(const vector <Stud>& studentai);

#endif // STUD_H_INCLUDED

