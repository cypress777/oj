#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int M = 100000;

int main() {

    double exp = 0;
    for (int k = 1; k <= M; k++) {
        double tot = 1.0 * k * k;
        double outer_area, inner_area;

        double r = k + 0.5;
        double rr = r * r;

        double outer_d = sqrt(rr - 1) - 1;
        double outer_D = outer_d * sqrt(2.0);
        double outer_theta_2 = asin(outer_D / 2.0 / r);
        double outer_fan = rr * outer_theta_2;
        double outer_tri = r * cos(outer_theta_2) * outer_D / 2.0;
        outer_area = outer_fan - outer_tri + outer_d * outer_d / 2.0;

        if (k == 1) {
            inner_area = 0;
        } else {
            r = k - 0.5;
            rr = r * r;
            double inner_d = sqrt(rr - 1) - 1;
            double inner_D = inner_d * sqrt(2.0);
            double inner_theta_2 = asin(inner_D / 2.0 / r);
            double inner_fan = rr * inner_theta_2;
            double inner_tri = r * cos(inner_theta_2) * inner_D / 2.0;
            inner_area = inner_fan -  inner_tri + inner_d * inner_d / 2.0;
        }

        double p = (outer_area - inner_area) / tot;

        exp += p * k;
        if (k % 1000 == 0) cout << k << " " << p << " " << k * p << " " << exp << " " << inner_area << " " << outer_area << " " << tot << endl;
    }

    cout << fixed << exp << endl;

    return 0;
}
