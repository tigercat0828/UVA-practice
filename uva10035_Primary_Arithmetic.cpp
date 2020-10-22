#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Digit;

void Int2Digits(int num, Digit& digits) {
    while (num > 10) {
        int d = num % 10;
        digits.push_back(d);
        num /= 10;
    }
    digits.push_back(num);
    digits.push_back(0);
}
void PrintVector(Digit& vec) {
    for (auto item : vec) {
        cout << item << ' ';
    }cout << endl;
}
int CheckCarry(Digit digitsA, Digit digitsB) {
    // adjust to same length
    Digit sum;
    for (int i = 0; i < digitsA.size(); i++) {
        sum.push_back(digitsA[i] + digitsB[i]);
    }
    int carryTimes = 0;
    for (int i = 0; i < sum.size() - 1; i++) {
        if (sum[i] >= 10) {
            sum[i] -= 10;
            sum[i + 1] += 1;
            carryTimes++;
        }
    }
    return carryTimes;
}
void AlignDigits(Digit digitsA, Digit digitsB) {
    int lenA = digitsA.size();
    int lenB = digitsB.size();
    int fillDigit = 0;
    if (lenA > lenB) {
        fillDigit = lenA - lenB;
        for (int i = 0; i < fillDigit; i++) {
            digitsB.push_back(0);
        }
    }
    else if (lenA < lenB) {
        fillDigit = lenB - lenA;
        for (int i = 0; i < fillDigit; i++) {
            digitsA.push_back(0);
        }
    }
    PrintVector(digitsA);
    PrintVector(digitsB);
}
int main() {

    Digit digitsA;
    Digit digitsB;
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 || b == 0) {
            break;
        }
        Int2Digits(a, digitsA);
        Int2Digits(b, digitsB);
        AlignDigits(digitsA, digitsB);
        int answer = CheckCarry(digitsA, digitsB);
        cout << answer << endl;
    }

    if (getchar())getchar();
    return 0;
}
/*

*/