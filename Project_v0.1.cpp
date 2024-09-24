#include <iostream>
#include "MyLib.h"
#include "Stud.h"


int main()
{
    vector <Stud> vec1;
    Stud temp;
    cout << "How many students do you have?";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Please input student data:" << endl;
        input(temp);
        skaiciuotiGalutiniBala(temp);
        vec1.push_back(temp);
        clean(temp);
    }
    cout << setw(15) << left << "Surname" << setw(10) << left << "Name" << setw(5) << right << "Final average score (vid)" << endl;
    for (int i = 0; i < n; i++)
        output(vec1.at(i));

    system("pause");

    return 0;
}

