#include "Stud.h"


double skaiciuotiNdVid(const vector <int>& nd){
    double sum = 0;
    for (int i = 0; i < nd.size(); i++) {
        sum += nd[i];
    }
    return sum / nd.size();
}
double skaiciuotiNdMed(vector <int>& nd) {
    sort(nd.begin(), nd.end());
    int size = nd.size();
    if (size % 2 == 0) {
        return (nd[size / 2 - 1] + nd[size / 2]) / 2.0;
    }
    else {
        return nd[size / 2];
    }
}

void skaiciuotiGalutiniBala(Stud& Lok) {
    Lok.galutinisVid = 0.4 * skaiciuotiNdVid(Lok.nd) + 0.6 * Lok.egz;
    Lok.galutinisMed = 0.4 * skaiciuotiNdMed(Lok.nd) + 0.6 * Lok.egz;
}

void input(Stud& Lok) {
    cout << "Input Name, Surname: ";
    cin >> Lok.vardas >> Lok.pavarde;

    Lok.nd.resize(4);

    cout << "Input 4 ND scores: ";
    for (int i = 0; i < 4; ++i) {
        cin >> Lok.nd[i];
        }

    cout << "Input Exam score: ";
    cin >> Lok.egz;
}

void output(Stud Lok) {
	cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas << setw(5) << setprecision(2) << fixed << right << Lok.galutinisVid << endl;
}

void clean(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.nd.clear();
}

