#include <iostream>
//#define debug
using namespace std;

int const iSize = 4;

void build (float fMatrix[][iSize])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j){
            cout << fMatrix[i][j] << " ";
        }
        cout << endl;
    }

}

void build (float fVector[])
{
    for (int i = 0; i < iSize; ++i)
        cout << fVector[i] << " ";
    cout << endl;
}


void fIncrease (float matrix [][iSize], float vector[], float fResultVector[])
{
    for (int i = 0; i < iSize; ++i)
    {
        fResultVector[i] = 0;
        for (int j = 0; j < iSize; ++j){
#ifdef debug
            cout << matrix[j][i] * vector[i] << endl;
#endif
            fResultVector[i] += matrix[j][i] * vector[i];
        }
    }
}

int main() {
    float fMatrix [iSize][iSize];
    float fVector [iSize];
    float fResultVector[iSize];

    std::cout << "Write matrix (16 elements):" << endl;
    for (int i = 0; i < iSize; ++i){
        for (int j = 0; j < iSize; ++j){
            cin >> fMatrix[i][j];
        }
    }

    std::cout << "Write vector (4 elements):" << endl;
    for (int i = 0; i < iSize; ++i){
        cin >> fVector[i];
    }

    std::cout << "Matrix:" << endl;
    build (fMatrix);

    std::cout << "Vector is not increase:" << endl;
    build (fVector);

    std::cout << "Vector increase:" << endl;

    fIncrease (fMatrix, fVector, fResultVector);
    build (fResultVector);

}