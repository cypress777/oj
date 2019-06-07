#include <iostream>
#include <vector>

using namespace std;

unsigned int reverse(unsigned int x) {
    unsigned int result = 0;
    while (x > 9) {
        auto digit = x % 10;
        result *= 10;
        result += digit;
        x /= 10;
    }

    return result * 10 + x;
}

bool only_odd(unsigned int x) {
    while (x > 0) {
        if (x % 2 == 0) return false;
        x /= 10;
    }
    return true;
}



int main() {
    unsigned int count = 0;

    for (unsigned int i = 11; i < 100000000; i += 2)
        if (only_odd(i + reverse(i))) count += 2;

    std::cout << count << std::endl;

    return 0;

}