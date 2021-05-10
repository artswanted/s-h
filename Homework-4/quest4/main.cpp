#include <iostream>
using namespace std;

int const iSize = 4;

bool comparedFunc (int matrix1[][iSize], int matrix2[][iSize])
{
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            if (matrix1[i][j] != matrix2[i][j]){
                return false;
            }
        }
    }
    return true;
}

void build (int matrix[][iSize])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

}

int main() {
    int iMatrix1 [iSize][iSize];
    int iMatrix2 [iSize][iSize];

    cout << "Write matrix1 numbers (16 elements):" << endl;
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            cin >> iMatrix1[i][j];
        }
    }

    cout << endl << "Write matrix2 numbers (16 elements):" << endl;
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            cin >> iMatrix2[i][j];
        }
    }

    cout << endl << "Matrix 1:" << endl;
    build (iMatrix1);

    cout << endl << "Matrix 2:" << endl;
    build (iMatrix2);

    cout << endl << "We are have the " << (comparedFunc (iMatrix1, iMatrix2) ? "the same" : "not same") << " matrices!";
}
