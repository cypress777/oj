#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int NN = 100000;
int MM = 1000000000;
int AA = 1000000;

int main() {
    srand((unsigned)time(NULL));

    ofstream fout("in.txt");

    int N = 100, S = N / 2, M = rand() % MM, T = N / 2 + 1;
    fout << N << " " << S << " " << M << " " << T << endl;

    int cur = AA - 1;
    for (int i = 0; i < N; i++) {
        fout << rand() % AA << " ";
    }

    return 0;
}