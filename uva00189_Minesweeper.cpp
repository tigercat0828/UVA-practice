#include <iostream>
#include <vector>
using namespace std;

class vec2 {
public:
    int x;
    int y;
    vec2(int x, int y) {
        this->x = x;
        this->y = y;
    }
    vec2() {
        x = y = -1;
    }
};
template<typename A>
void PrintGrid(A grid[][100], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
void LoadGrid(vector<vec2>& mineList, char grid[][100], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char token; cin >> token;
            if (token == '*')   mineList.push_back(vec2(i, j));
            grid[i][j] = token;
        }
    }
}
void ResetMine(int mineGrid[][100], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mineGrid[i][j] = 0;
        }
    }
}
void PrintAnswer(int mineGrid[][100], vector<vec2>& mineList, int height, int width) {
    char answer[100][100];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            answer[i][j] = mineGrid[i][j] + '0';
        }
    }
    for (size_t i = 0; i < mineList.size(); i++) {
        int x = mineList[i].x;
        int y = mineList[i].y;
        answer[x][y] = '*';
    }
    PrintGrid(answer, height, width);
}
void CalcMineSum(vector<vec2>& mineList, int mineGrid[][100], int height, int width) {

    for (size_t k = 0; k < mineList.size(); k++) {
        int i = mineList[k].x;
        int j = mineList[k].y;
        // around the cell
        for (int x = i - 1; x <= i + 1; x++) {
            for (int y = j - 1; y <= j + 1; y++) {
                if (x < 0 || x >= height || y < 0 || y >= width) {
                    continue;
                }
                mineGrid[x][y]++;
            }
        }
    }
}

int main() {

    int height, width;
    char TokenGird[100][100] = { 'x' };
    int MineGrid[100][100] = { 0 };
    int field = 0;
    vector<vec2> mineList;
    while (cin >> height >> width) {
        field++;
        if (height == 0 || width == 0) break;
        // reset
        ResetMine(MineGrid, height, width);
        mineList.clear();
        // load 
        LoadGrid(mineList, TokenGird, height, width);
        PrintGrid(TokenGird, height, width);

        // calc
        CalcMineSum(mineList, MineGrid, height, width);
        // output
        cout << "Field #" << field << endl;
        PrintAnswer(MineGrid, mineList, height, width);
        cout << endl;
    }
    return 0;
}
/*
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
*/