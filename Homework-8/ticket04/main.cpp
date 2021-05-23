#include <iostream>

void countEvenDigits (long long num, int &ans)
{
    if (num > 0)
        countEvenDigits (num / 10, ans);
    ans += ((num % 10) % 2 == 0);
}

int main() {
    std::cout << "Input number:";
    long long number;
    std::cin >> number;

    int ans = 0;
    countEvenDigits (number, ans);

    std::cout << "Count even digits is " << ans;
}