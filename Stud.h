#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "MyLib.h"

struct Stud {
	std::string vardas, pavarde;
	int nd, egz;
	double vid;
};

void skaiciuotiGalutiniBala(Stud& Lok);
void input(Stud& Lok);
void output(Stud Lok);
void clean(Stud& Lok);

#endif // STUD_H_INCLUDED


