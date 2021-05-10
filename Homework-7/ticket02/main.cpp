#include <iostream>

int* revert (int* arr1, int* arr2){
    for (int i = 9; i > 0; --i){
        *(arr2 + i) = *(arr1 + 9 - i);
    }
    return arr2;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int arrayRevert[10];
    int* pArray = array;
    int* pArrayRevert = arrayRevert;

    pArrayRevert = revert(pArray, pArrayRevert);

    for (int i = 0; i < 10; ++i){
        std::cout << *(pArrayRevert + i) << ' ';
    }
    return 0;
}
