#include <iostream>
using namespace std;

int main() {
    int sta, end;
    cin >> sta >> end;

    int cnt = 0;
    for (int year = sta; year <= end; year++) {
        int ry = year % 10;
        int y = year / 10;
        while (y > 0) {
            ry *= 10;
            ry += y % 10;
            y /= 10;
        }
//        cout << ry << " " << year << endl;
        if (ry - year >= 1000) cnt++;
    }

    cout << cnt << endl;
    return 0;
}