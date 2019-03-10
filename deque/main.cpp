#include "functions.h"
#include "libraries.h"

int main() {

    auto start = high_resolution_clock::now();
    int nr = 5; 
    int longestName, longestSurname;
    int N = 3;
    deque<stud> Students;
    deque<stud> Weak;
    string file = "kursiokai.txt";
    //Read(N, Students, longestName, longestSurname, nr);
    //Read_from_file(Students, longestName, longestSurname, file);
    //Sort_By_firstName(Students);
    //Write(Students, longestName, longestSurname);
    New_Students (Students, longestName, longestSurname, Weak);
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    cout << "Visos programos veikimas uztruko: " << diff.count() << " s/n" << endl;

    return 0;
}