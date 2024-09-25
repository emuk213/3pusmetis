#include <iostream>
#include "MyLib.h"
#include "Stud.h"


int main()
{
    vector <Stud> vec1;
    Stud temp;
    int a, n, b;
    string failoVardas;
    cout << "Do you want Final score with vid or med (0 - vid, 1 - med)?" << endl;
    cin >> a;
    cout << "Do you want to read data from txt file (1 - yes, 0 - no)?" << endl;
    cin >> b;
    if (b == 1) {
        cout << "Input file name" << endl;
        cin >> failoVardas;
        try {
            readStudTxt(failoVardas, vec1);
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
            return 1;  // Exit if there's an error
        }
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

    }
    else if(b == 0){
        cout << "How many students do you have?" << endl;
        cin >> n;
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
        else if (a == 1){
            cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (med.)" << endl;
            for (int i = 0; i < n; i++)
                outputMed(vec1.at(i));
        }
        
    }

    system("pause");

    return 0;
}
