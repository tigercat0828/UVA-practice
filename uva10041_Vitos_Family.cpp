#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void PrintArray(int* street, int length) {
    for (size_t i = 0; i < length; i++) {
        cout << street[i] << " ";
    }cout << endl;
}
int main() {
    int numCase;
    cin >> numCase;

    for (size_t i = 0; i < numCase; i++) {
        int relatives;
        cin >> relatives;
        // load street number
        int* street = new int[relatives];
        for (size_t j = 0; j < relatives; j++) {
            cin >> street[j];
        }

        // sort street number
        sort(street, street + relatives);
        int middle = street[relatives / 2];
        int sum = 0;
        for (size_t t = 0; t < relatives; t++) {
            sum += abs((middle - street[t]));
        }
        cout << sum << endl;
        delete[] street;
    }

    if (getchar())getchar();
}

/*
2
2 2 4
3 2 4 6
*/
