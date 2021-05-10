#include <iostream>

void swap2 (int* a, int* b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main() {
    int a, b;
    std::cout << "Input a and b: ";
    std::cin >> a >> b;
    std::cout << a << " " << b << std::endl;
    std::swap(a, b);
    std::cout << a << " " << b << std::endl;
    swap2(&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;
}