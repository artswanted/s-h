#include <iostream>
using namespace std;

int const iSize = 5;
int const iHeight = 10;


void initalFilling (bool arr[][iSize][iHeight])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j)
        {
            for (int k = 0; k < iHeight; ++k)
                arr[i][j][k] = false;
        }
    }
}


void heightFilling (bool arr[][iSize][iHeight])
{
    for (int i = 0; i < iSize; ++i)
    {
        for (int j = 0; j < iSize; ++j)
        {
            cout << "Input height (0-10) for square on (" << i << ", " << j << "): ";
            int height;
            do
            {
                cin >> height;
            } while (height < 0 || height > 10);
            for (int k = 0; k < height; ++k)
                arr[i][j][k] = true;
        }
    }
}


void checkLevel (bool arr[][iSize][iHeight])
{
    bool mark = true;
    do
    {
        cout << "Input level for scan (1-10): ";
        int lvl;
        do
        {
            cin >> lvl;
        } while (lvl < 1 || lvl > 10);

        for (int i = 0; i < iSize; ++i)
        {
            for (int j = 0; j < iSize; ++j)
                cout << arr[i][j][lvl-1] << " "; // lvl-1 преобразовываем индексы для 0-9 массива
            cout << endl;
        }

        cout << "Scan level again? (y/n): ";
        char answer;
        do
        {
            cin >> answer;
        } while (answer != 'y' && answer != 'n');
        mark = (answer == 'y');
    } while (mark);
}


int main() {
    bool landscape[iSize][iSize][iHeight];

    initalFilling (landscape);
    heightFilling (landscape);
    checkLevel (landscape);

    cout << "End program";
}