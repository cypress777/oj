#include <iostream>
#include <cmath>

using namespace std;

class BigNum {
private:
  unsigned long long num_[201];
  unsigned long long base_;
public:
  BigNum(): base_(pow(10, 10)) {};
  BigNum(unsigned long long base): base_(base){};

  BigNum operator*(int);
  BigNum operator+(BigNum);
  BigNum operator+(int);

  ~BigNum() = default;
}

  BigNum::operator*(int num) {
    unsigned long long tmp = num_[0] * num;
    num_[0] = tmp % base_;
    num_[1] += tmp / base_;
  }

  BigNum::operator+(BigNum other) {

  }

  BigNum::operator+(int num) {
 
  }

int main() {
  int a, b, c, N;
  cin >> a >> b >> c >> N;

  unsigned long long newBorneds = 1;
  unsigned long long ones = 0;
  unsigned long long twos = 0;
  unsigned long long threeMores = 0;
  unsigned long long rabbits = newBorneds;
  unsigned long long bigNum[201]{0};

  int n = 0;
  while (n++ < N) {
    threeMores += twos;
    twos = ones;
    ones = newBorneds;
    newBorneds = ones * a + twos * b + threeMores * c;    
  }
  rabbits = newBorneds + ones + twos + threeMores;

  cout << rabbits;
  return 0;
}
