#include <iostream>

int* revert (int* pArray, int* pArrayRevert){
    for (int i = 0; i < 10; ++i){
        *(pArrayRevert + i) = *(pArray + (10 - 1 - i));
    }
    return pArrayRevert;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrayRevert[10];
    int* pArray = array;
    int* pArrayRevert = arrayRevert;

    pArrayRevert = revert(pArray, pArrayRevert);

    for (int i = 0; i < 10; ++i){
        std::cout << *(pArrayRevert + i) << ' ';
    }
    return 0;
}
