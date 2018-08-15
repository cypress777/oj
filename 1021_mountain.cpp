#include <iomanip>
#include <iostream>
 
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  int map[N][N];
  int round = N/2;
  int value = 0;
 
  if (N%2) 
    map[N/2][N/2] = N*N;

  for (int i = 0; i < round; i++) {
    for (int k = 0; k < (N - 2*i); k++) {
      map[i + k][i] = ++value;
    }
    for (int k = 1; k < (N - 2*i); k++) {
      map[N - i - 1][i + k] = ++value;
    }
    for (int k = 1; k < (N - 2*i); k++) {
      map[N - i - 1 - k][N - i - 1] = ++value;
    }
    for (int k = 1; k < (N - 2*i - 1); k++) {
      map[i][N - i - 1 - k] = ++value;
    }
  }
 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << setw(6) << map[j][i];
    }
  cout << endl;
  }
return 0;
}
