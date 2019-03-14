#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;
int main() {
    string str1;
    string str2;
    long i, j, n, exp, di, dj;
    long v1, v2, value, carry = 0, resCarry = 0;
    unordered_map<long, long> result;

    cin >> str1;
    cin >> str2;
    
// interval 10exp6
    long inter = 6;
    for (j = 0; j < str2.size(); j++) {
        for (i = 0; i < str1.size(); i++) {
            di = str1.size() - i - 1;
            dj = str2.size() -j - 1;
            exp = (i + j) % inter;
            n = (i + j) / inter;

            v1 = (long)(str1[di]) - 48;
            v2 = (long)(str2[dj]) - 48;

            value = (v1 * v2 + carry) % 10 * (long)pow(10, exp);
            carry = (v1 * v2 + carry) / 10;
 
//            cout << value << " ";
//            cout << carry << endl;
           
            resCarry = (result[n] + value) / (long)pow(10, inter);
            result[n] = (result[n] + value) % (long)pow(10, inter);
            while (resCarry > 0) {
                n++;
                result[n] += resCarry;
                resCarry = result[n] / (long)pow(10, inter);
                result[n] = result[n] % (long)pow(10, inter); 
            }
//cout << i << "," << j << ":" << resCarry << " " << result[n] << endl;
        }
    }
    n = (i + j - 1) / inter;
    exp = (i + j - 1) % inter;
//cout << "n:" << n << " exp:" << exp << endl;
    value = carry % 10 * (long)pow(10, exp);
//    cout << value << endl;
  
    resCarry = (result[n] + value) / (long)pow(10, inter);
    result[n] = (result[n] + value) % (long)pow(10, inter);
    while (resCarry > 0) {                         
        n++;                                       
        result[n] += resCarry;                     
        resCarry = result[n] / (long)pow(10, inter); 
        result[n] = result[n] % (long)pow(10, inter);
    }
//cout << i << "," << j << ":" << resCarry << " " << result[n] << endl;

    std::stringstream resString;
    for (i = 0; i < result.size(); i++) {
//        cout << result[i] << " * 10exp" << 6*i << endl;
        if (i == 0) {
            resString << result[result.size() - i - 1]; 
        } else {
            resString << setfill('0') << setw(6) << result[result.size() - i - 1]; 
        } 
    }
    cout << resString.str() << endl;
}
