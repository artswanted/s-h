#include <iostream>
using namespace std;

int const iSize = 4;

void build (int matrix[][iSize])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

}

void matrixConvert (int matrix[][iSize])
{
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            if (i != j){
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int iMatrix1 [iSize][iSize];

    cout << "Write matrix1 numbers (16 elements):" << endl;
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            cin >> iMatrix1[i][j];
        }
    }


    cout << endl << "Matrix 1:" << endl;
    build (iMatrix1);


    cout << endl <<"Converted matrix to diaginal:" << endl;
    matrixConvert(iMatrix1);
    build (iMatrix1);
}