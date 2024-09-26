#include <iostream>
#include <limits>
#include "MyLib.h"
#include "Stud.h"


int main()
{
    vector <Stud> vec1;
    Stud temp;
    int a, n, b;
    string failoVardas;
    cout << "Do you want Final score with vid or med (0 - vid, 1 - med)?" << endl;
    try {
        cin >> a;
        if (cin.fail() || (a != 0 && a != 1)) {
            throw runtime_error("Error: wrong input");
        }

        cout << "Do you want to read data from txt file (0 - no, 1 - yes)?" << endl;

        cin >> b;
        if (cin.fail() || (b != 0 && b != 1)) {
            throw runtime_error("Error: wrong input");
        }
        


        if (b == 1) {
            cout << "Input file name" << endl;
            cin >> failoVardas;
            
            readStudTxt(failoVardas, vec1);
            
            if (a == 0) {
                cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (vid.)" << endl;
                for (Stud& student : vec1) {
                    skaiciuotiGalutiniBala(student);
                    outputVid(student);
                }
            }
            else if (a == 1) {
                cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (med.)" << endl;
                for (Stud& student : vec1) {
                    skaiciuotiGalutiniBala(student);
                    outputMed(student);
                }
            }

            /* Atspausdina duomenis is txt file
               outputTxt(vec1);
            */
        }



        else if (b == 0) {
            cout << "How many students do you have?" << endl;
            
            cin >> n;
            if (cin.fail()) {
                throw runtime_error("Error: input must be a number");
            }
            
            for (int i = 0; i < n; i++) {
                cout << "Please input student data:" << endl;
                input(temp);
                skaiciuotiGalutiniBala(temp);
                vec1.push_back(temp);
                clean(temp);
            }
            if (a == 0) {
                cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (vid.)" << endl;
                for (int i = 0; i < n; i++)
                    outputVid(vec1.at(i));
            }
            else if (a == 1) {
                cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (med.)" << endl;
                for (int i = 0; i < n; i++)
                    outputMed(vec1.at(i));
            }

        }
    }
     catch (exception& e) {
         cerr << e.what() << endl;
         return 1;
     }

    system("pause");

    return 0;
}
