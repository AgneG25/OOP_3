#include "functions.h"
#include "libraries.h"

int main() {

    auto start = high_resolution_clock::now();
    int nr = 5; 
    int longestName, longestSurname;
    int N = 3;
    vector<stud> Students;
    //Read(N, Students, longestName, longestSurname, nr);
    //Read_from_file(Students, nr, longestName, longestSurname);
    //Sort_By_firstName(Students);
    //Write(Students, longestName, longestSurname);
    New_Students (Students, nr, longestName, longestSurname);
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    cout << "Visos programos veikimas uztruko: " << diff.count() << " s/n" << endl;

    return 0;
}