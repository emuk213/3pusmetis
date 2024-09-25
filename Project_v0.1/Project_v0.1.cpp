#include <iostream>
#include "MyLib.h"
#include "Stud.h"


int main()
{
    vector <Stud> vec1;
    Stud temp;
    int a, n;
    cout << "Do you want Final score with vid or med (0 - vid, 1 - med)?" << endl;
    cin >> a;
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
    else {
        cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (med.)" << endl;
        for (int i = 0; i < n; i++)
            outputMed(vec1.at(i));
    }

    system("pause");

    return 0;
}
