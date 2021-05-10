#include <iostream>

int main() {
    int a = 20;
    int b = 40;
    int* pa = &a;
    int* pb = &b;
    std::cout << *pa << " " << *pb << std::endl;
    std::swap(a, b);
    std::cout << *pa << " " << *pb << std::endl;
    return 0;
}
