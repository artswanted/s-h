#include <iostream>
#include <vector>

void sort (std::vector <int> &vec)
{
    for (int i = vec.size() - 1; (i > 0) && (vec[i] < vec[i-1]); --i)
    {
        int temp = vec[i];
        vec[i] = vec[i-1];
        vec[i-1] = temp;
    }
}

int main() {
    std::vector <int> vec;

    int iValue;
    std::cout << "Write any number (-1 for output; -2 for exit):" << std::endl;
    do
    {
        std::cin >> iValue;

        if (iValue == -1)
        {
            if (vec.size() < 5)
                std::cout << "You have not five elements yet!" << std::endl;
            else
                std::cout << "Your fifth element is " << vec[4] << std::endl;
        } else if (iValue != -2) {
            if (vec.size() < 5)
            {
                vec.push_back(iValue);
                sort (vec);
            } else if (iValue < vec[4]) {
                vec[4] = iValue;
                sort (vec);
            }
        }
    } while (iValue != -2);
}