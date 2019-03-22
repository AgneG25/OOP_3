#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

struct stud {
    
    string firstName;
    string secondName;
    vector<double> homework;
    double exam;

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
    double Average() {
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
    bool string_is_valid(const string x) {
        string spec_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (x.find_first_not_of(spec_char) != string::npos)
            return false;
        else return  true;
    }
};

void Read (int N, vector<stud> &Students, int &longestName, int &longestSurname, int nr);
void Read_from_file(vector<stud> &Students, int &longestName, int &longestSurname, string filename);
void Write (vector<stud> &Students, int &longestName, int &longestSurname);
bool Compare_By_firstName(const stud &a, const stud &b);
void Sort_By_firstName(vector<stud> &Students);
void New_Students (vector<stud> &Students, int &longestName, int &longestSurname, vector<stud> &Weak, vector<stud> &Strong);
void PrintByMarks (int n, vector<stud> &Weak, vector<stud> &Strong);
void SortByMarks(vector<stud> &Students, vector<stud> &Weak, vector<stud> &Strong);

#endif
