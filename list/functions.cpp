#include "functions.h"
#include "libraries.h"

void CheckLetter (string &name) {
    if(islower(name[0]))
        name[0] = toupper(name[0]);
}

/*void Read (int N, list<stud> &Students, int &longestName, int &longestSurname, int nr) {

    longestName = 0;
    longestSurname = 0;
    stud S = {};
    double mark, exam;
    int n, b;
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
    }*/
//-------------------------------------------------------------------------
void Read_from_file(list<stud> &Students, int &longestName, int &longestSurname, string filename) {
    int mark;
    stud S = {};
    longestName = 0;
    longestSurname = 0;

    std::ifstream ifs (filename.c_str());
    
    while(!ifs.eof()){

        ifs >> S.firstName >> S.secondName;

        CheckLetter(S.firstName);
        CheckLetter(S.secondName);

        ifs >> S.exam;
        
        if(ifs) {
            S.homework.clear();
            double mark;
            while (ifs >> mark) S.homework.push_back(mark);
            ifs.clear();
        }
        
        if (S.firstName.size() > longestName) 
            longestName = S.firstName.size();
        if (S.secondName.size() > longestSurname) 
            longestSurname = S.secondName.size();
            Students.push_back(S);
    }
        Students.pop_back();

        ifs.close();
    }
//-------------------------------------------------------------------------
/*void Write (list<stud> &Students, int &longestName, int &longestSurname) {

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

bool Compare_By_firstName(const stud &a, const stud &b) {
    return a.firstName < b.firstName;
}

void Sort_By_firstName(list<stud> &Students) {
    std::sort(Students.begin(), Students.end(), Compare_By_firstName);
}
*/
void New_Students (list<stud> &Students, int &longestName, int &longestSurname, list<stud> &Weak){


    for (int i = 1; i <= 5; i++) {
        string file = std::to_string(i) + ".txt";
        
        Read_from_file(Students, longestName, longestSurname, file);
        SortByMarks(Students, Weak);
        PrintByMarks(i, Students, Weak);
        
    }
}

void PrintByMarks (int n, list<stud> &Students, list<stud> &Weak) {

    auto start = high_resolution_clock::now();

    int count = 0;
    std::ofstream rf1 (std::to_string(n) + "vargsiukai.txt");
    std::ofstream rf2 (std::to_string(n) + "galvociai.txt");
    
    for (auto &i : Students) {
        rf2 << i.firstName << " " << i.secondName << " " << i.Average() << endl;
        count++;
    }
    Students.clear();

    for (auto &i : Weak) {
        rf1 << i.firstName << " " << i.secondName << " " << i.Average() << endl;
        count++;
    }
    Weak.clear();

    rf1.close();
    rf2.close();
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    cout << count << " elementu uzpildymas uztruko: " << diff.count()  << " s/n" << endl;
}

void SortByMarks(list<stud> &Students, list<stud> &Weak) {

    list<stud> Strong;

    for (auto &i : Students) {
        if (i.Average() < 5) {
            Weak.push_back(i);
        }
        else {
            Strong.push_back(i);
        }
    }
    Students = Strong;
    Strong.clear();
}
