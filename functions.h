#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

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
        double ave = 0;
        
        for(int i = 0; i < homework.size(); i++) S+= homework[i];

        try {
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

void Read (int N, vector<stud> &Students, int &longestName, int &longestSurname, int nr);
void Read_from_file(vector<stud> &Students, int nr, int &longestName, int &longestSurname);
void Write (vector<stud> &Students, int &longestName, int &longestSurname);
bool compare_By_firstName(const stud &a, const stud &b);
void sort_By_firstName(vector<stud> &Students);

#endif