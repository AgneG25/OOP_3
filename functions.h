#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"


class Person {
protected:
    string firstName;
    string secondName;
    vector<double> homework;
    double exam;

public:
    Person() : exam(0) {}
};

class stud: public Person {
public:
    stud() : Person{}{ }
    void setFirstName (string x) { firstName = x; }
    void setSecondName (string y) { secondName = y; }
    void setExam (double e) { exam = e; }
    void setMark (double mark) { homework.push_back(mark); }
    
    inline string getFirstName() const { return firstName; }
    inline string getSecondName() const { return secondName; }
    inline double getExam() const { return exam; }
    int getMark(int a) const { return homework[a]; }
    void cleanMark() { homework.clear(); }

    friend std::ostream & operator << (std::ostream & out, const stud a) {
        out << a.getFirstName() << " " << a.getSecondName() << " " << a.Average() << endl;
        return out;
    }

    friend std::istream &operator >> (std::istream & in, stud& a) {
        int marks;
        int val;
        cout << "Iveskite studento varda: ";
        in >> a.firstName;
        cout << "Iveskite studento pavarde: ";
        in >> a.secondName;
        cout << "Iveskite pazymiu skaiciu: ";
        in >> marks;
        for (int i = 0; i < marks; i++) {
            cout << "Iveskite pazymi: ";
            in >> val;
            if (val < 1 || val > 10) {
                cout << "Bloga reiksme, veskite is naujo" << endl;
                i--;
                continue;
            }
            a.homework.push_back(val);
        }
        cout << "Iveskite egzamino rezultata: ";
        in >> val;
        if (val < 1 || val > 10) a.exam = 1;
        else a.exam = val;
        return in;
    }
    friend bool operator == (const stud &a, const stud &b) { return a.Average() == b.Average(); }
    friend bool operator != (const stud &a, const stud &b) { return a.Average() != b.Average(); }
    friend bool operator > (const stud &a, const stud &b) { return a.getFirstName() > b.getFirstName(); }
    friend bool operator < (const stud &a, const stud &b) { return a.getFirstName() < b.getFirstName(); }
    friend bool operator >= (const stud &a, const stud &b) { return a.Average() >= b.Average(); }
    friend bool operator <= (const stud &a, const stud &b) { return a.Average() <= b.Average(); }

    void RandomE() { //sugeneruojamas egzamino pazymys
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 10);
        exam = dist(mt);
    }
    void Random() { //sugeneruojamas namu darbu pazymys
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 10);
        double r = dist(mt);
        homework.push_back(r);
    }
    double Average() const {
        double S = 0;
        double ave = 0;
        
        for(int i = 0; i < homework.size(); i++) S+= homework[i];
        ave = S/homework.size();

        try { //tikrinama ar yra namu darbu pazymiu
            if (homework.size() == 0){
                throw 0;
            }
            return 0.4 * ave + 0.6 * exam;
        } catch (...) {
            return 0;
        }
    }
    double Med() {
        size_t size = homework.size();
        int m = 0;

        if (size == 0)
            throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    
        std::sort(homework.begin(), homework.end());
        if (size % 2 == 0)
            m = (double)(homework[size/2] + homework[size/2 - 1])/2;
        else 
            m = (double)homework[size/2];
    
        
        return 0.4 * m + 0.6 * exam;
    }

};
bool string_is_valid(const string x);
void Read (int N, vector<stud> &Students, int &longestName, int &longestSurname);
void Read_from_file(vector<stud> &Students, int &longestName, int &longestSurname, string filename);
void Write (vector<stud> &Students, int &longestName, int &longestSurname);
bool Compare_By_firstName(const stud &a, const stud &b);
void Sort_By_firstName(vector<stud> &Students);
void New_Students (vector<stud> &Students, int &longestName, int &longestSurname);
bool Passed (stud &a);
void PrintByMarks (int n, vector<stud> &Students);
vector<stud> SortByMarks(vector<stud> &Students);

#endif
