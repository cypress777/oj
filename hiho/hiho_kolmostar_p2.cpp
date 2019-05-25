#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>
        A = {{ 1, -1, -1, -1, -1, -1, -1,  1, -1},

        { 1, -1, -1, -1, -1, -1,  1, -1, -1},

        { 1, -1, -1, -1,  1, -1, -1, -1, -1},

        { 1, -1, -1, -1,  1,  1,  1,  1,  1},

        { 1, -1, -1,  1, -1,  1, -1,  1,  1},

        { 1, -1, -1,  1,  1, -1,  1, -1,  1},

        { 1, -1, -1,  1,  1,  1, -1, -1, -1},

        { 1, -1, -1,  1,  1,  1, -1,  1,  1},

        { 1, -1,  1, -1, -1,  1,  1,  1, -1},

        { 1, -1,  1, -1,  1, -1, -1,  1,  1},

        { 1, -1,  1, -1,  1,  1, -1, -1, -1},

        { 1, -1,  1,  1, -1, -1, -1,  1, -1},

        { 1, -1,  1,  1, -1, -1, -1,  1,  1},

        { 1, -1,  1,  1, -1, -1,  1, -1,  1},

        { 1, -1,  1,  1,  1,  1,  1, -1,  1},

        { 1,  1, -1, -1, -1, -1, -1, -1,  1},

        { 1,  1, -1, -1, -1,  1, -1, -1, -1},

        { 1,  1, -1, -1, -1,  1,  1,  1,  1},

        { 1,  1, -1, -1,  1, -1,  1, -1,  1},

        { 1,  1, -1,  1, -1,  1, -1, -1,  1},

        { 1,  1, -1,  1,  1, -1, -1,  1, -1},

        { 1,  1, -1,  1,  1,  1,  1,  1, -1},

        { 1,  1,  1, -1, -1, -1, -1, -1, -1},

        { 1,  1,  1, -1,  1,  1, -1, -1,  1},

        { 1,  1,  1, -1,  1,  1,  1,  1,  1},

        { 1,  1,  1,  1, -1,  1,  1, -1, -1},

        { 1,  1,  1,  1,  1, -1,  1,  1, -1},

        { 1,  1,  1,  1,  1,  1, -1,  1,  1}};

vector<int> B(9, 0);

// this method takes 247 ops
void MatrixMult(const vector<int> &B, vector<int> &res) {
     vector<int> a_sum(28, 0);
     for (int i = 0; i < 28; i++) {
          for (int j = 0; j < 9; j++) {
               a_sum[i] += A[i][j];
          }
     }

     vector<int> B2(9, 0);
     for (int i = 0; i < 9; i++) {
          B2[i] = 2 * B[i];
     }


     int all_sum = 0;
     int minus_all_sum = 0;

     for (int i = 0; i < 9; i++) {
          all_sum += B[i];
     }
     minus_all_sum = -all_sum;

     res = vector<int>(28, 0);
     for (int i = 0; i < 28; i++) {
          if (a_sum[i] < 0) {
               res[i] = minus_all_sum;
               for (int j = 0; j < 9; j++) {
                    if (A[i][j] > 0) {
                         res[i] += B2[j];
                    }
               }
          } else {
               res[i] = all_sum;
               for (int j = 0; j < 9; j++) {
                    if (A[i][j] < 0) {
                         res[i] -= B2[j];
                    }
               }
          }
     }
};

int main() {
     for (int i = 0; i < 9; i++) {
          cin >> B[i];
     }

     vector<int> res;
     MatrixMult(B, res);

     for (int i = 0; i < 28; i++) cout << res[i] << " ";
     cout << endl;

     return 0;
};