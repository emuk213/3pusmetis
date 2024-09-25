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
    size_t size = nd.size();
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

    cout << "Do you want randomized ND and Exam scores (0-no, 1-yes)?" << endl;
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
void readStudTxt(const string& failoVardas, vector <Stud>& studentai) {
    ifstream inFile(failoVardas); //atidarome faila nuskaitymui
    if (!inFile.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo: " + failoVardas);
    }
    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        istringstream iss(line);
        Stud Lok1;
        int score;

        iss >> Lok1.pavarde >> Lok1.vardas;

        Lok1.nd.clear();
        for (int i = 0; i < 5; ++i) {
            iss >> score;
            Lok1.nd.push_back(score);
        }

        iss >> Lok1.egz;

        studentai.push_back(Lok1);
    }
}




void outputTxt(const vector<Stud>& studentai) {
   
    cout << setw(15) << left << "Pavarde"
        << setw(15) << left << "Vardas"
        << setw(30) << left << "Namu darbai"
        << setw(10) << left << "Egzaminas" << endl;

    cout << string(70, '-') << endl;

    for (const auto& student : studentai) {
       
        cout << setw(15) << left << student.pavarde
            << setw(15) << left << student.vardas;


        for (size_t i = 0; i < student.nd.size(); ++i) {
            cout << student.nd[i];
            if (i < student.nd.size() - 1) {
                cout << " ";
            }
        }

        cout << setw(10) << right << student.egz << endl;
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

