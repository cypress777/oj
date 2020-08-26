#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    int rel = 0, t_pos = 0, sel = 0;
    for (int i = 0; i < N; i++) {
        char sample, detecion;
        cin >> sample >> detecion;

        if (sample == '+') rel++;

        if (detecion == '+') {
            sel++;
            if (sample == '+') t_pos++;
        }
    }

    double res = 2 * double(t_pos * t_pos) / double(rel * t_pos + sel * t_pos) * 100;
    cout << fixed << setprecision(2) << res  << "%" << endl;

    return 0;
}
