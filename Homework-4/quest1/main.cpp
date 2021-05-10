#include <iostream>
using namespace std;

int const x = 2;
int const y = 6;

void printArray (int array[x][y], string text){
    cout << text << endl;
    for (int a = 0; a < x; a++){
        for (int b = 0; b < y; b++){
            cout << array [a][b] << " ";
        }
        cout << endl;
    }
}

int main() {

    int table [x][y] = {1, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0};

    int fork [x][y] = {1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1};

    int spoon [x][y] = {1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1};

    int knife [x][y] = {1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1};

    int spoonDesert [x][y] = {1, 0, 0, 0, 0, 0,
                               1, 0, 0, 0, 0, 0};

    int plate [x][y] = {2, 2, 2, 2, 2, 2,
                        2, 2, 2, 2, 2, 2};

    int plateDesert [x][y] = {1, 0, 0, 0, 0, 0,
                               1, 0, 0, 0, 0, 0};

    int chair [x][y] = {1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1};

    //пришла дама с ребенком, нужен +1 стул
    chair [0][4]++;

    //украли ложку, ряд 2, место 3
    spoon[1][2]--;

    //вип поделился ложкой
    spoon[1][0]--;
    spoon[1][2]++;

    //официант забрал тарелку для десерта у випа
    plateDesert[1][0]--;

    printArray (table, "VIP persons");
    printArray (spoon, "Spoons");
    printArray (knife, "Knifes");
    printArray (fork, "Forks");
    printArray (spoonDesert, "Desert spoons");
    printArray (plate, "plates");
    printArray (plateDesert, "desert plates");
    printArray (chair, "Chairs");
    return 0;
}
