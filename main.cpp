#include "functions.h"
#include "libraries.h"

int main() {

    int N = 2;
    int nr = 5; 
    int longestName, longestSurname;
    vector<stud> Students;
    //Read(N, Students, longestName, longestSurname, nr);
    Read_from_file(Students, nr, longestName, longestSurname);
    sort_By_firstName(Students);
    Write(Students, longestName, longestSurname);

    return 0;
}