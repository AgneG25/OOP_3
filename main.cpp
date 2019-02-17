#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <stdlib.h> 

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::setprecision;
using std::fixed;
using std::sort;
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
    void Sort() {
        int max, t;
        for (int i = 0; i < homework.size() - 1; i++){
            max = i;
            for (int j = i + 1; j < homework.size(); j++){
                if (homework[j] < homework[max])
                max = j;
            }
        t = homework[max];
        homework[max] = homework[i];
        homework[i] = t;
        }  
    }
    double Med() {
        Sort();
        int m = 0;
        if(homework.size()%2 == 0) 
            m = (homework[homework.size()/2] + homework[homework.size()/2 - 1])/2;
        else m = homework[homework.size()/2];
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
void Read (int N, stud Students[], int &longestName, int &longestSurname) {
    longestName = 0;
    longestSurname = 0;
    double mark;
    double exam;
    int n;
    int a;
    string firstName, secondName;

    for (int i = 0; i < N; i++){
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

        Students[i].firstName = firstName;
        Students[i].secondName = secondName;
         
        cout << "Jei norite, kad pazymiai buti automatiskai sugeneruojami, paspauskite 1, jei ne - 0 " << endl;
        cin >> a;
        if(a == 1){
            Students[i].Random();
            cout << "Jei norite, kad butu sugeneruotas dar viena pazymys, spauskite 1, jei ne - 0: " << endl;
            cin >> n;
            while (n == 1) {
                Students[i].Random();
                cout << "Jei norite, kad butu segeneruotas dar viena pazymys, spauskite 1, jei ne - 0: " << endl;
                cin >> n;
            }
            }
            
        else {
            do {
            cout << "Iveskite pazymi: ";
            cin >> mark;
            if(mark <= 10 && mark >=1){
                Students[i].homework.push_back(mark);
            }
            else {
                cout << "Iveskite pazymi is naujo, (intervale nuo 1 iki 10): ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> mark;
            }
            cout << "Jei norite ivesti dar viena pazymi, spauskite vieneta, jei ne - 0 " << endl;
            cin >> n;
            }while(n == 1);
            }

            cout << "Iveskite egzamino rezultata: ";
            cin >> exam;
            if(exam <= 10 && exam >=1){
                Students[i].exam = exam;
            }
            else {
                cout << "Iveskite pazymi is naujo, (intervale nuo 1 iki 10): ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> exam;
            }
        
        cout << endl;
        
        if (Students[i].firstName.size() > longestName) 
            longestName = Students[i].firstName.size();
        if (Students[i].secondName.size() > longestSurname) 
            longestSurname = Students[i].secondName.size();
    }}
//-------------------------------------------------------------------------
void Write (int N, stud Students[], int longestName, int longestSurname) {

    char a;
    cout << "Pasirinkite ka norite matyti, jei mediana, iveskite 'm', jei vidurki - 'v'." << endl;
    cin >> a;
    
    while (!((!cin.fail()) && ((a == 'm') || (a == 'v')))) {
        cout << "Netinkamas atsakymas, iveskite 'm' arba 'v': ";
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

    if (a == 'm')
        cout << "Galutinis (Med.)" << endl;
    else
        cout << "Galutinis (Vid.)" << endl;

    string line (longestName + longestSurname + 21, '-');
    cout << line << endl;

    for (int i = 0; i < N; i++){
        cout << left << setw(longestName + 2) << Students[i].firstName;
        cout << left << setw(longestSurname + 2) << Students[i].secondName;
        if (a == 'm')
            cout << left << setw(19) << fixed << setprecision(2) << Students[i].Med();
        else 
            cout << left << setw(19) << fixed << setprecision(2) << Students[i].Average();
        cout << endl;
    }}
//------------------------------------------------------------------------
int main() {

    int N = 2;
    int longestName, longestSurname;
    stud Students[N];
    Read(N, Students, longestName, longestSurname);
    Write(N, Students, longestName, longestSurname);

    return 0;
}