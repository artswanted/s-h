#include <iostream>
using namespace std;
const int iSize = 12;

void build (bool bMatrix[][iSize])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j){
            cout << ((bMatrix[i][j]) ? "O" : "X");
        }
        cout << endl;
    }
}

bool bEmpty (bool matrix[][iSize])
{
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            if (matrix[i][j]){
                return true;
            }
        }
    }
    return false;
}

int input ()
{
    int iNumber;
    do{
        std::cin >> iNumber;
        if ((iNumber < 0) || (iNumber >= iSize))
            std::cout << "Wrong number. Try again." << endl;
        else{
            return iNumber;
        }
    } while (true);
}

void pops (bool matrix[][iSize], int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
    {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2)
    {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }

    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            if (matrix[i][j])
            {
                matrix[i][j] = false;
                cout << "Pop!";
            }
        }
    }
    cout << endl << endl;
}

int main() {

    bool bMatrix [iSize][iSize];

    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j) {
            bMatrix[i][j] = true;
        }
    }

    build (bMatrix);

    do {
        std::cout << "Enter start coordinates (0-12)";
        int x1, y1;
        x1 = input();
        y1 = input();

        std::cout << "Enter end coordinates (0-12)";
        int x2, y2;
        x2 = input();
        y2 = input();

        pops(bMatrix, x1, y1, x2, y2);

        build(bMatrix);
    } while (bEmpty(bMatrix));

    cout << "The end!";
}