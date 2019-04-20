#include "functions.h"
#include "libraries.h"
#include "console.h"

int main() {

    auto start = high_resolution_clock::now();
    int longestName, longestSurname;
    const int imax = std::numeric_limits<int>::max();

    vector<stud> Students;
    vector<stud> Weak;

    cout << "Pasirinkite atitinkamus skaicius, jeigu norite:" << endl;
    cout << "1 - Nuskaityti duomenis is esamo failo" << endl;
    cout << "2 - Naudoti automatiskai sugeneruotus duomenis" << endl;
    cout << "3 - Ivesti duomenis" << endl;

    int Choice = Console::GetInteger(1,3);
    string file = "kursiokai.txt";

     if (Choice == 1) 
    {
        Read_from_file(Students, longestName, longestSurname, file); 
        Sort_By_firstName(Students);
        Write (Students, longestName, longestSurname);
    }       
    else if (Choice == 2) 
    {
        New_Students (Students, longestName, longestSurname);
    }
    else if (Choice == 3)
    {
        cout << "Kiek norite ivesti studentu? " << endl;
        int N = Console::GetInteger(1,imax);

        Read(N, Students, longestName, longestSurname);
        Write (Students, longestName, longestSurname);
    } 

    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    cout << "Visos programos veikimas uztruko: " << diff.count() << " s/n" << endl;

    return 0;
}