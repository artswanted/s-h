#include <iostream>
#include <string>

enum pianoKeys{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

void pianoSound (int ch)
{
    int sound = 1 << ch;

    if (sound & DO) std::cout << "DO ";
    else if (sound & RE) std::cout << "RE ";
    else if (sound & MI) std::cout << "MI ";
    else if (sound & FA) std::cout << "FA ";
    else if (sound & SOL) std::cout << "SOL ";
    else if (sound & LA) std::cout << "LA ";
    else std::cout << "SI ";
}


int main() {
   int const combNotes = 12;
    int temp;
    std::string combination;

    for (int i = 1; i <= combNotes; ++i)
    {
        std::cout << "Input " << i << " combination of notes from " << combNotes << ": ";
         do {
            std::cin >> temp;
            if (temp <= 7 && temp >= 1) break;
            else std::cout << "Wrong note. Try again:";
        } while (true);

        combination += std::to_string(temp);
    }

    int i = 0;
    while ((i < combination.length()) &&
           (((combination[i] - '0') >= 1) && (combination[i] - '0' <= 7)))
    {
        pianoSound(combination[i] - '1');
        ++i;
    }
    if (i != combination.length())
        std::cout << "Input notes is incorrect";

    return 0;
}
