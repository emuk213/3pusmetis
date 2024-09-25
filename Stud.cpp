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

    cout << "Do you want randomized ND and Exam scores (0-no, 1-yes)?";
    int ats;
    cin >> ats;
    if (ats == 0) {
        cout << "Input ND scores (press non numeric symbol and ENTER to finish): ";
        int paz;

        while (cin >> paz) {
            Lok.nd.push_back(paz);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input Exam score: ";
        cin >> Lok.egz;
    }
    else {
        int ndSk = 1 + rand() % 10;
        for (int i = 0; i < ndSk; i++) {
            Lok.nd.push_back(1 + (rand() % 10));
        }
        //isveda random nd vec:
        ///for (int i = 0; i < Lok.nd.size(); ++i) {
          //  cout << Lok.nd[i] << " ";
       // }
        //cout << endl;
        Lok.egz = 1 + (rand() % 10);
        //isveda random egzamino rezultata:
        ///cout << Lok.egz << endl;
        
    }
}

void outputVid(Stud Lok) {
	cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas << setw(5) << setprecision(2) << fixed << right << Lok.galutinisVid << endl;
}
void outputMed(Stud Lok) {
    cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas << setw(5) << setprecision(2) << fixed << right << Lok.galutinisMed << endl;
}

void clean(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.nd.clear();
}

