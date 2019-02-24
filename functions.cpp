#include "functions.h"
#include "libraries.h"

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
         
        cout << "Ar norite, kad pazymiai butu sugeneruojami automatiskai? t/n" << endl;
        cin >> ans;
        
        while (!((!cin.fail()) && ((ans == 't') || (ans == 'n')))) {
        cout << "Netinkamas atsakymas, iveskite 't', arba 'n': ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> ans;
        }
        
        if(ans == 't') {

            cout << "Jei norite sugeneruoti pazymi, spauskite 't', jei nebenorite - bet kuri kita klavisa." << endl;
            cin >> ans;
        
            while(ans == 't') {
                S.Random();
                cout << "Jei norite sugeneruoti pazymi, spauskite 't', jei nebenorite - bet kuri kita klavisa." << endl;
                cin >> ans;
            }
        }
        else {
            cout << "Jei norite ivesti pazymi, spauskite 't', kitu atveju spauskite bet kuri klavisa." << endl;
            cin >> ans;
            while(ans == 't') {
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
            }
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
        string line (longestName + longestSurname + 24, '-');
        cout << line << endl;
    }
    else {
        cout << "Galutinis (Med.) Galutinis (Vid.)" << endl;
        string line (longestName + longestSurname + 41, '-');
        cout << line << endl;
    }
    
    for (auto &i : Students) {

        cout << left << setw(longestName + 2) << i.firstName;
        cout << left << setw(longestSurname + 2) << i.secondName;

        if (a == 'm'){
            cout << left << setw(17) << fixed << setprecision(2) << i.Med();
        }
        else if (a == 'v'){
            if (i.Average() != 0)
                cout << left << setw(17) << fixed << setprecision(2) << i.Average();
            else
                cout << left << setw(17) << fixed << setprecision(2) << "Dalyba is 0 negalima." << endl;
        }
        else {
             cout << left << setw(17) << fixed << setprecision(2) << i.Med();

            if (i.Average() != 0)
                cout << left << setw(17) << fixed << setprecision(2) << i.Average();
            else
                cout << left << setw(17) << fixed << setprecision(2) << "Dalyba is 0 negalima." << endl;;
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