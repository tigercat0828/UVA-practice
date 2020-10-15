#include <iostream>
#include <cmath>
using namespace std;

int main() {

    long long int ally, enemy;
    while (cin >> ally >> enemy) {
        cout << abs(ally - enemy) << endl;
    }
    return 0;
}