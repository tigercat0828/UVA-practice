#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> tmp1 = { 0,1,2,3,4,5,6,7 };
    vector<int> tmp2 = { 0,1,2,3,4,5,6,7 };
    vector<int> tmp3 = { 0,1,2,3,4,5,6,7 };
    vector<int> tmp4 = { 0,1,2,3,4,5,6,7 };
    vector<vector<int>> T;
    T.push_back(tmp1);
    T.push_back(tmp2);
    T.push_back(tmp3);
    T.push_back(tmp4);
    cout << T[1][2] << endl;

    if (getchar())getchar();
}