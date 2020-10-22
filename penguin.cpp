#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void PrintVector(vector<int> vec) {
    for (auto item : vec) {
        cout << item << ' ';
    }
    cout << endl;
}
vector<int> Intersection(vector<int>& vecA, vector<int>& vecB) {
    vector<int> answer;
    for (int i = 0; i < vecA.size(); i++) {
        answer.push_back(vecA[i] * vecB[i]);
    }
    return answer;
}
void Process(vector<int>& cellFormat, vector<int>& head, vector<int>& tail) {
    for (int i = 1; i < cellFormat.size(); i++) {
        for (int j = 0; j < cellFormat[i]; j++) {
            head.push_back(1);
        }
        if (i < cellFormat.size()) {
            head.push_back(0);
        }
    }
    reverse(cellFormat.begin() + 1, cellFormat.end());
    for (int i = 1; i < cellFormat.size(); i++) {
        for (int j = 0; j < cellFormat[i]; j++) {
            tail.push_back(1);
        }
        if (i < cellFormat.size()) {
            tail.push_back(0);
        }
    }
    reverse(tail.begin(), tail.end());
}
int main() {

    int temp;
    vector<int> cellFormat;
    while (cin >> temp) {
        cellFormat.push_back(temp);
    }
    vector<int> head, tail;
    vector<int> answer;

    Process(cellFormat, head, tail);
    cout << "head: "; PrintVector(head);
    cout << "tail: "; PrintVector(tail);

    answer = Intersection(head, tail);
    PrintVector(answer);

    if (getchar())getchar();
}
/*

10 4 1 2
11110 10110
01111 01011
01110 00010
*/