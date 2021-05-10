#include <iostream>

bool iCheckColumn (std::string iField, char iSymbol)
{
    for (int i = 0; i < 3; ++i)
        if ((iField[i] == iField[i+3]) && (iField[i+3] == iField[i+6]) && iField[i] == iSymbol)
            return true;
    return false;
}

bool iCheckRow (std::string iField, char iSymbol)
{
    for (int i = 0; i < 3; ++i)
        if (((iField[i + 2 * i]) == iField[(i + 1) + 2 * i]) &&
            ((iField[(i + 1) + 2 * i]) == iField[(i + 2) + 2 * i]) &&
                iField[i + 2 * i] == iSymbol)
            return true;
    return false;
}

bool iCheckingV2 (std::string iField, char iSymbol)
{
    for (int i = 0; i < 3; ++i)
        if ((((iField[0] == iField[4]) && (iField[4] == iField[8])) ||
             ((iField[2] == iField[4]) && (iField[4] == iField[6]))) &&
            (iField[4] == iSymbol))
            return true;
    return false;
}

bool iWinner (std::string iField, char iSymbol)
{
    return (iCheckColumn(iField, iSymbol) ||
            iCheckRow(iField, iSymbol) ||
            iCheckingV2(iField, iSymbol));
}

int iCheckCount (std::string iField, char iSymbol)
{
    int iFieldSize = 9;
    int count = 0;
    for (int i = 0; i < iFieldSize; ++i)
        if (iField[i] == iSymbol)
            ++count;
    return count;
}

bool iCorrectType (std::string iField)
{
    for (int i = 0; i < 9; ++i)
        if (iField[i] != 'X' && iField[i] != 'O' && iField[i] != '.')
            return false;
    return true;
}

int main() {
    std::string iField;
    int iFieldSize = 9;

    for (int i = 1; i < 4; ++i)
    {
        std::cout << "Write " << i << " row (X, O, '.'): ";
        std::string temp;
        std::cin >> temp;
        iField += temp;
    }

    if ((iField.length() == iFieldSize) && iCorrectType(iField))
    {
        int countX = iCheckCount(iField, 'X');
        int countO = iCheckCount(iField, 'O');

        if ((countX - countO == 0) || (countX - countO == 1))
        {
            bool iWinnerX = iWinner (iField, 'X');
            bool iWinnerO = iWinner (iField, 'O');

            if ((iWinnerX && iWinnerO) ||
                (iWinnerO && (countX - countO == 1)) ||
                (iWinnerX && (countX - countO == 0)))
                std::cout << "Incorrect" << std::endl;
            else
            if (!iWinnerX && !iWinnerO)
                std::cout << "No one win!" << std::endl;
            else
                std::cout << (iWinnerX ? "Petya is winner!" : "Vanya is winner!") << std::endl;
        }
        else
            std::cout << "Incorrect" << std::endl;
    }
    else
        std::cout << "Incorrect" << std::endl;
}