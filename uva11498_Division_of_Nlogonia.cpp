#include <iostream>
using namespace std;

void LocateQuadrant(int centerX, int centerY, int placeX, int placeY) {
    if (placeX == centerX || placeY == centerY) {
        printf("divisa\n");
    }
    else if (placeX > centerX && placeY > centerY) {
        printf("NE\n");
    }
    else if (placeX < centerX && placeY > centerY) {
        printf("NO\n");
    }
    else if (placeX < centerX && placeY < centerY) {
        printf("SO\n");
    }
    else if (placeX > centerX && placeY < centerY) {
        printf("SE\n");
    }
}
int main() {
    int caseNum;
    while (cin >> caseNum) {
        if (caseNum == 0) {
            break;
        }
        int centerX, centerY;
        cin >> centerX >> centerY;
        for (int i = 0; i < caseNum; i++) {
            int placeX, placeY;
            cin >> placeX >> placeY;
            LocateQuadrant(centerX, centerY, placeX, placeY);
        }
    }
}

/* sample input
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0
*/
/* sample output
NE
divisa
NO
divisa
NE
SO
SE
*/