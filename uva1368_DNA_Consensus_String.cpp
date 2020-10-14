#include <iostream>
#include <string>
#include <vector>
using namespace std;
void PrintList(vector<string> list) {
    for (auto item : list) {
        cout << item << endl;
    }
}
int main() {

    int caseNum;
    cin >> caseNum;
    vector<string> DNAlist;

    for (size_t h = 0; h < caseNum; h++) {
        DNAlist.clear();
        int num, length;
        cin >> num >> length;
        for (size_t i = 0; i < num; i++) {
            string tempDNA; cin >> tempDNA;
            DNAlist.push_back(tempDNA);
        }
        PrintList(DNAlist);

    }
    return 0;
}