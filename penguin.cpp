#include <iostream>
#include <vector>
using namespace std;


void PrintVector(vector<int> vec) {
    for (auto item : vec) {
        cout << item << endl;
    }
}
int main() {

    int temp;

    vector<int> cellFormat;
    while (cin >> temp) {
        cellFormat.push_back(temp);

    }
    return 0;
}