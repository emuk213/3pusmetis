#include "Stud.h"

void skaiciuotiGalutiniBala(Stud& Lok) {
	Lok.vid = 0.4 * Lok.nd + 0.6 * Lok.egz;
}

void input(Stud& Lok) {
	cout << "Input Name, Surname, ND and Exam score:";
	cin >> Lok.vardas >> Lok.pavarde >> Lok.nd >> Lok.egz;
}

void output(Stud Lok) {
	cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas << setw(5) << setprecision(2) << fixed << right << Lok.vid << endl;
}

void clean(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
}


