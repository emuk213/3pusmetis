#include <iostream>
#include "MyLib3.h"
#include "Stud3.h"
#include "Timer.h"


int main()
{
    list <Stud> list1, sigma, beta;
    Stud temp;
    int a, b, c, f, g, h, x, strategija;
    string failoVardas;
    cout << "Ar norite atlikti testus arba generuoti naujus failus (0-ne, 1-taip)?" << endl;
    cin >> h;
    if (h == 0) {
        cout << "Do you want Final score with vid or med (0 - vid, 1 - med)?" << endl;
        try {
            cin >> a;
            if (cin.fail() || (a != 0 && a != 1)) {
                throw runtime_error("Error: wrong input");
            }
            cout << "By what do you want to sort the data (0 - name, 1 - surname, 2 - final score?" << endl;
            cin >> x;
            cout << "Do you want to read data from txt file (0 - no, 1 - yes)?" << endl;

            cin >> b;
            if (cin.fail() || (b != 0 && b != 1)) {
                throw runtime_error("Error: wrong input");
            }

            if (b == 1) {
                cout << "Input file name" << endl;
                cin >> failoVardas;

                readStudTxt(failoVardas, list1);

                for (Stud& student : list1) {
                    skaiciuotiGalutiniBala(student);
                }
                sortByChoice(list1, x);
                output(list1, a);
            }

            else if (b == 0) {
                cout << "How many students do you have?" << endl;

                cin >> g;
                if (cin.fail()) {
                    throw runtime_error("Error: input must be a number");
                }

                for (int i = 0; i < g; i++) {
                    cout << "Please input student data:" << endl;
                    input(temp);
                    skaiciuotiGalutiniBala(temp);
                    list1.push_back(temp);
                    clean(temp);
                }

                sortByChoice(list1, x);
                output(list1, a);
            }
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }
    if (h == 1) {

        cout << "Ar norite generuoti naujus studentu sarasu failus? (0-ne, 1-taip)" << endl;
        cin >> c;
        if (c == 1) {
            int d = 1000;

            for (int i = 0; i < 5; i++) {

                kurti_faila("studentai" + to_string(d) + ".txt", d);
                d *= 10;
            }

        }

        cout << "Pagal ka norite rusiuoti duomenis? (0-varda, 1-pavarde, 2-galutini bala)" << endl;
        cin >> f;
        cout << "Kokia strategija norite naudoti (1, 2, 3)?" << endl;
        cin >> strategija;

        int n = 1000;
        for (int i = 0; i < 5; i++) {
          
            Timer t;
            readStudTxt("studentai" + to_string(n) + ".txt", list1);
            double e = t.elapsed();
            cout << "\nFailo is " + to_string(n) + " irasu nuskaitymas uztruko: " << e << " s\n";


            for (Stud& temp : list1) {
                skaiciuotiGalutiniBala(temp);
            }
            Timer t1;
            sortByChoice(list1, f);
            double e1 = t1.elapsed();
            cout << to_string(n) + " irasu rusiavimas uztruko: " << e1 << " s\n";

           if (strategija == 1) {
                Timer t2;

                kategorijos(list1, sigma, beta);
                double e2 = t2.elapsed();
                cout << to_string(n) + " irasu dalinimas i 2 grupes uztruko: " << e2 << " s\n";

                Timer t3;
                isvedimas(sigma, "sigma" + to_string(n) + ".txt");
                double e3 = t3.elapsed();
                cout << to_string(n) + " irasu sigma irasymo i faila uztruko: " << e3 << " s\n";

                Timer t4;
                isvedimas(beta, "beta" + to_string(n) + ".txt");
                double e4 = t4.elapsed();
                cout << to_string(n) + " irasu beta irasymo i faila uztruko: " << e4 << " s\n";

                double totalTime = e + e1 + e2 + e3 + e4;
                cout << "\n" + to_string(n) + " irasu testo laikas: " << totalTime << " s\n";
            }

           else if (strategija == 2) {
                Timer t2;

                kategorijos2(list1, beta);
                double e2 = t2.elapsed();
                cout << to_string(n) + " irasu dalinimas i 2 grupes uztruko: " << e2 << " s\n";

                Timer t3;
                isvedimas(list1, "sigma" + to_string(n) + ".txt");
                double e3 = t3.elapsed();
                cout << to_string(n) + " irasu sigma irasymo i faila uztruko: " << e3 << " s\n";

                Timer t4;
                isvedimas(beta, "beta" + to_string(n) + ".txt");
                double e4 = t4.elapsed();
                cout << to_string(n) + " irasu beta irasymo i faila uztruko: " << e4 << " s\n";

                double totalTime = e + e1 + e2 + e3 + e4;
                cout << "\n" + to_string(n) + " irasu testo laikas: " << totalTime << " s\n";
            }
            else if (strategija == 3) {
               Timer t2;

               kategorijos3(list1, beta);
               double e2 = t2.elapsed();
               cout << to_string(n) + " irasu dalinimas i 2 grupes uztruko: " << e2 << " s\n";
               sortByChoice(list1, f);
               sortByChoice(beta, f);

               Timer t3;
               isvedimas(list1, "sigma" + to_string(n) + ".txt");
               double e3 = t3.elapsed();
               cout << to_string(n) + " irasu sigma irasymo i faila uztruko: " << e3 << " s\n";

               Timer t4;
               isvedimas(beta, "beta" + to_string(n) + ".txt");
               double e4 = t4.elapsed();
               cout << to_string(n) + " irasu beta irasymo i faila uztruko: " << e4 << " s\n";

               double totalTime = e + e1 + e2 + e3 + e4;
               cout << "\n" + to_string(n) + " irasu testo laikas: " << totalTime << " s\n";
           }
            n *= 10;
        }
    }
    system("pause");
    return 0;
}