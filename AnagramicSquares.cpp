#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool is_valid(int n, const vector<int> &aidx, const vector<int> &bidx) {
    vector<int> flg(aidx.size(), -1);
    int bn = 0;
    // n for a, formulate bn
    int base_i = static_cast<int>(pow(10, aidx.size()));
    for (int i = 0; i < aidx.size(); i++) {
        base_i /= 10;
        int ni = n / base_i % 10;
        int base_j = base_i;
        for (int j = i + 1; j < aidx.size(); j++) {
            base_j /= 10;
            int nj = n / base_j % 10;
            if (aidx[j] == aidx[i] && ni != nj) return false;
            if (aidx[j] != aidx[i] && ni == nj) return false;
        }
        for (int j = 0; j < aidx.size(); j++) {
            if (flg[j] == -1 && bidx[j] == aidx[i]) {
                flg[j] = 1;
                if (j == 0 && ni == 0) return false;
                bn += ni * static_cast<int>(pow(10, aidx.size() - j - 1));
            }
        }
    }
    int sqb = static_cast<int>(sqrt(bn));
    if (sqb * sqb != bn) return false;
    return true;
}

bool is_pair(const string &sa, const string &sb, vector<int> &aidx, vector<int> &bidx) {
    if (sa.size() != sb.size()) return false;

    aidx = vector<int>(sa.size(), -1);
    bidx = vector<int>(sa.size(), -1);
    vector<int> flg(sa.size(), -1);

    for (int i = 0; i < sa.size(); i++) {
        if (aidx[i] == -1) {
            aidx[i] = i;
            for (int j = i + 1; j < sa.size(); j++) {
                if (aidx[j] != -1) continue;
                if (sa[j] == sa[i]) aidx[j] = aidx[i];
            }
        }

        bool has_a = false;
        for (int j = 0; j < sa.size(); j++) {
            if (flg[j] == -1 && sb[j] == sa[i]) {
                flg[j] = 1;
                has_a = true;
                bidx[j] = aidx[i];
                break;
            }
        }
        if (!has_a) return false;
    }
    return true;
}

int cal(const vector<int> &aidx, const vector<int> &bidx) {
    int digits = aidx.size();
    int max_range = pow(10, digits);
    int min_range = pow(10, digits - 1);
    for (int i = static_cast<int>(sqrt(max_range)); i > static_cast<int>(sqrt(min_range)); i--) {
        int n = i * i;
        if (is_valid(n, aidx, bidx) || is_valid(n, bidx, aidx)) return n;
    }
    return -1;
}

int main() {
    ifstream fin("p098_words.txt", ifstream::in);
    vector<string> words;

    while (fin.good()) {
        string s;
        fin >> s;
        words.push_back(s);
    }

    int max_sq = 0;
    string max_a;
    string max_b;
    for (int i = 0; i < words.size(); i++) {
        string sa = words[i];
        for (int j = i + 1; j < words.size(); j++) {
            string sb = words[j];
            vector<int> aidx, bidx;
            if (!is_pair(sa, sb, aidx, bidx)) continue;
            int sq = cal(aidx, bidx);
            if (sq > max_sq) {
                max_sq = sq;
                max_a = sa;
                max_b = sb;
            }
        }
    }

    cout << max_sq << " " << max_a << " " << max_b << endl;

    return 0;
}