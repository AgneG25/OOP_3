#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <stdlib.h> 
#include <fstream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::setprecision;
using std::fixed;
using std::vector;


struct stud {
    
    string firstName;
    string secondName;
    vector<double> homework;
    double exam;

    void RandomE() {
        std::srand(std::time(nullptr));
        exam = std::rand() % 10 + 1;
    }
    void Random() {
        std::srand(std::time(nullptr));
        double r = std::rand() % 10 + 1;
        homework.push_back(r);
    }
    double Average() {
        double S = 0;
        for(int i = 0; i < homework.size(); i++) S+= homework[i];
        double ave = S/homework.size();
        return 0.4 * ave + 0.6 * exam;
    }
    double Med() {
        size_t size = homework.size();
        
        int m = 0;
        if (size == 0)
            m = 0;
        else {
            std::sort(homework.begin(), homework.end());
            if (size % 2 == 0)
                m = (double)(homework[size/2] + homework[size/2 - 1])/2;
            else 
                m = (double)homework[size/2];
            }
        
        return 0.4 * m + 0.6 * exam;
    }
    bool string_is_valid(const string x) {
        string spec_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (x.find_first_not_of(spec_char) != string::npos)
            return false;
        else return  true;
    }
};
//----------------------------------------------------------------
void Read (int N, vector<stud> &Students, int &longestName, int &longestSurname, int nr) {
    longestName = 0;
    longestSurname = 0;
    stud S = {};
    double mark;
    double exam;
    int n;
    int b;
    string firstName, secondName;
    char ans;

    
    for (int i = 0; i < N; i++){
        S.homework.clear();
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> firstName >> secondName;

            if(!(Students[i].string_is_valid(firstName))){
            cout << "Iveskite varda is naujo, naudokite tik raides: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> firstName;
            }

            if (!(Students[i].string_is_valid(secondName))){
                cout << "Iveskite pavarde is naujo, naudokite tik raides: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> secondName;
            }
        
        S.firstName = firstName;
        S.secondName = secondName;
         
        cout << "Jei norite, kad pazymiai butu automatiskai sugeneruojami, paspauskite 't, jei ne - 'n' " << endl;
        cin >> ans;
        
        while (!((!cin.fail()) && ((ans == 't') || (ans == 'n')))) {
        cout << "Netinkamas atsakymas, iveskite 't', arba 'n': ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> ans;
        }
        
        if(ans == 't') {
            do {
                S.Random();
                cout << "Jei norite sugeneruoti dar viena pazymi, spauskite 't', jei nebenorite - bet kuri kita klavisa." << endl;
                cin >> ans;
            } while(ans == 't');
        }
        else {
            do {
            cout << "Iveskite pazymi: ";
            cin >> mark;
            
            if(mark <= 10 && mark >=1){
                S.homework.push_back(mark);
            }
            else {
                while (!(mark <= 10 && mark >=1)){
                    cout << "Iveskite pazymi is naujo, (intervale nuo 1 iki 10): ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> mark;  
                }
            }
            cout << "Jei norite ivesti dar viena pazymi, spauskite 't', kitu atveju spauskite bet kuri klavisa." << endl;
            cin >> ans;
            } while(ans == 't');
            }

            cout << "Iveskite egzamino rezultata: ";
            cin >> exam;
            if (exam <= 10 && exam >=1) {
                S.exam = exam;
            }
            else {
                while (!(mark <= 10 && mark >=1)){
                    cout << "Iveskite pazymi is naujo, (intervale nuo 1 iki 10): ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> mark;  
                }
            }
        
        cout << endl;
        
        if (S.firstName.size() > longestName) 
            longestName = S.firstName.size();
        if (S.secondName.size() > longestSurname) 
            longestSurname = S.secondName.size();
        Students.push_back(S);
    }
    }
//-------------------------------------------------------------------------
void Read_from_file(vector<stud> &Students, int nr, int &longestName, int &longestSurname) {
    int mark;
    stud S = {};
    string s;
    int sTotal = 0;
    longestName = 0;
    longestSurname = 0;

    std::ifstream ifs ("kursiokai.txt");

    S.homework.clear();
    while(!ifs.eof()){

        ifs >> S.firstName >> S.secondName;

        for(int j = 0; j < nr; j++){
            ifs >> mark;
            S.homework.push_back(mark);
        }
        ifs >> S.exam;
        ifs.ignore();

        if (S.firstName.size() > longestName) 
            longestName = S.firstName.size();
        if (S.secondName.size() > longestSurname) 
            longestSurname = S.secondName.size();
            Students.push_back(S);
    }

        ifs.close();
    }
//-------------------------------------------------------------------------
void Write (vector<stud> &Students, int &longestName, int &longestSurname) {

    char a;
    cout << "Pasirinkite ka norite matyti: jei mediana, iveskite 'm', jei vidurki - 'v', jei abu - 'a'." << endl;
    cin >> a;
    
    while (!((!cin.fail()) && ((a == 'm') || (a == 'v') || (a == 'a')))) {
        cout << "Netinkamas atsakymas, iveskite 'm', 'a' arba 'v': ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> a;
        }

    if(longestName < 8)
        longestName = 8;
    cout << left << setw(longestName + 2) << "Vardas";

    if (longestSurname < 8)
        longestSurname = 8;
    cout << left << setw(longestSurname + 2) << "Pavarde";

    if (a == 'm'){
        cout << "Galutinis (Med.)" << endl;
        string line (longestName + longestSurname + 21, '-');
        cout << line << endl;
    }
    else if (a == 'v'){
        cout << "Galutinis (Vid.)" << endl;
        string line (longestName + longestSurname + 21, '-');
        cout << line << endl;
    }
    else {
        cout << "Galutinis (Vid.) Galutinis (Med.)" << endl;
        string line (longestName + longestSurname + 38, '-');
        cout << line << endl;
    }
    
    for (auto &i : Students) {

        cout << left << setw(longestName + 2) << i.firstName;
        cout << left << setw(longestSurname + 2) << i.secondName;

        if (a == 'm'){
            cout << left << setw(17) << fixed << setprecision(2) << i.Med();
        }
        else if (a == 'v'){
            cout << left << setw(17) << fixed << setprecision(2) << i.Average();
        }
        else {
             cout << left << setw(17) << fixed << setprecision(2) << i.Med();
             cout << left << setw(17) << fixed << setprecision(2) << i.Average();
        }
        cout << endl;
    }
    }

bool compare_By_firstName(const stud &a, const stud &b) {
    return a.firstName < b.firstName;
}

void sort_By_firstName(vector<stud> &Students) {
    std::sort(Students.begin(), Students.end(), compare_By_firstName);
}
//---------------------------------------------------------------------------
int main() {

    int N = 2;
    int nr = 5; // pazymiu skaicius
    int longestName, longestSurname;
    vector<stud> Students;
    //Read(N, Students, longestName, longestSurname, nr);
    Read_from_file(Students, nr, longestName, longestSurname);
    sort_By_firstName(Students);
    Write(Students, longestName, longestSurname);

    return 0;
}
