#include <iostream>

int const iSizeField = 10;

void initalFilling(bool arr[][iSizeField])
{
    for (int i = 0; i < iSizeField; ++i)
        for (int j = 0; j < iSizeField; ++j)
            arr[i][j] = false;
}

int convert(char x)
{
    return (((x - 'A' >= 0) && (x - 'A' <= 9)) ? (x - 'A') : (x - 'a'));
}

bool isNotNearShip(bool arr[][iSizeField], int x, int y)
{
    int i0, i1, j0, j1;
    if (x - 1 >= 0) j0 = x - 1;
    else j0 = x;
    if (x + 1 <= iSizeField) j1 = x + 1;
    else j1 = x;
    if (y - 1 >= 0) i0 = y - 1;
    else i0 = y;
    if (y + 1 <= iSizeField) i1 = y + 1;
    else i1 = y;

    for (int i = i0; i < i1; ++i)
        for (int j = j0; j < j1; ++j)
            if (arr[i][j]) return false;
    return true;
}

bool isNotNearShip(bool arr[][iSizeField], int x0, int y0, int x1, int y1)
{
    int i0, i1, j0, j1;
    if (x0 > x1)
    {
        int temp = x1;
        x1 = x0;
        x0 = temp;
    }
    if (y0 > y1)
    {
        int temp = y1;
        y1 = y0;
        y0 = temp;
    }

    if ((x0 - x1 == 0) || (y0 - y1 == 0))
    {
        if (x0 - 1 >= 0) j0 = x0 - 1;
        else j0 = x0;
        if (x1 + 1 <= iSizeField) j1 = x1 + 1;
        else j1 = x1;
        if (y0 - 1 >= 0) i0 = y0 - 1;
        else i0 = y0;
        if (y1 + 1 <= iSizeField) i1 = y1 + 1;
        else i1 = y1;

        for (int i = i0; (i < i1); ++i)
            for (int j = j0; (j < j1); ++j)
                if (arr[i][j]) return false;
        return true;
    }
    else
    {
        std::cout << "Wrong input coordinates. Try again" << std::endl;
        return false;
    }

}


void shipsPlacement(bool arr[][iSizeField], int size, int count)
{
    std::cout << std::endl << "Input coordinates (A-J or a-j)(1-10) for " << count << " ships with ship size " << size << std::endl;
    if (size == 1)
    {
        bool correct = false;
        for (int i = 0; i < count; ++i)
        {
            char x;
            int xInt, y;
            do
            {
                do
                {
                    std::cin >> x >> y;
                    xInt = convert(x);

                    --y;
                    if ((xInt < 0 || xInt > 9) || (y < 0 || y > 9))
                        std::cout << "Wrong input coordinates. Try again" << std::endl;
                } while ((xInt < 0 || xInt > 9) || (y < 0 || y > 9) || arr[xInt][y]);

                correct = isNotNearShip(arr, xInt, y);
                if (correct)
                {
                    arr[xInt][y] = true;
                    std::cout << "Ship placed on (" << x << y+1 << ")" << std::endl;
                }
                else std::cout << "Can't place ship there. Input coordinates again" << std::endl;
            } while (!correct);
        }
    }
    else
    {
        bool correct = false;
        for (int i = 0; i < count; ++i)
        {
            char x0, x1;
            int x0Int, x1Int, y0, y1;
            do
            {
                do
                {
                    std::cout << "Input start of ship coordinates (A-J or a-j)(1-10):" << std::endl;
                    std::cin >> x0 >> y0;
                    std::cout << "Input end of ship coordinates (A-J or a-j)(1-10):" << std::endl;
                    std::cin >> x1 >> y1;
                    x0Int = convert(x0);
                    x1Int = convert(x1);
                    --y0;
                    --y1;

                    if (x0 > x1)
                    {
                        int temp = x1;
                        x1 = x0;
                        x0 = temp;
                    }
                    if (y0 > y1)
                    {
                        int temp = y1;
                        y1 = y0;
                        y0 = temp;
                    }

                    if ((x0Int < 0 || x0Int > 9) || (y0 < 0 || y0 > 9) ||
                        (x1Int < 0 || x1Int > 9) || (y1 < 0 || y1 > 9) ||
                        ((x1Int - x0Int != size - 1) && (y1 - y0 != size - 1)) ||
                        !isNotNearShip(arr, x0Int, y0, x1Int, y1))
                        std::cout << "Wrong input coordinates. Try again" << std::endl;
                } while ((x0Int < 0 || x0Int > 9) || (y0 < 0 || y0 > 9) ||
                         (x1Int < 0 || x1Int > 9) || (y1 < 0 || y1 > 9) ||
                         ((x1Int - x0Int != size - 1) && (y1 - y0 != size - 1)) ||
                         !isNotNearShip(arr, x0Int, y0, x1Int, y1));

                correct = isNotNearShip(arr, x0Int, y0, x1Int, y1);

                if (correct)
                {
                    for (int i = x0Int; i <= x1Int; ++i)
                        for (int j = y0; j <= y1; ++j)
                            arr[i][j] = true;
                    std::cout << std::endl << "Ship placed on (" << x0 << y0 + 1 << ")-(" << x1 << y1 + 1 << ")" << std::endl;
                }
                else std::cout << "Can't place ship there. Input coordinates again" << std::endl;
            } while (!correct);
        }
    }
}


bool isEmpty(bool arr[][iSizeField])
{
    for (int i = 0; i < iSizeField; ++i)
        for (int j = 0; j < iSizeField; ++j)
            if (arr[i][j]) return false;
    return true;
}


void checkShot(bool arr[][iSizeField], char x, int y)
{
    int xInt = convert(x);

    if (arr[xInt][y])
    {
        std::cout << "Shot!" << std::endl;
        arr[xInt][y] = false;
    }
    else std::cout << "Miss" << std::endl;
}



void out(bool arr[][iSizeField])
{
    for (int i = 0; i < iSizeField; ++i)
    {
        for (int j = 0; j < iSizeField; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}


int main() {
    bool battlegroundA[iSizeField][iSizeField];
    initalFilling(battlegroundA);
    bool battlegroundB[iSizeField][iSizeField];
    initalFilling(battlegroundB);


    std::cout << std::endl << "Player A put your ships " << std::endl;
    for (int i = 1; i < 5; ++i)
        shipsPlacement(battlegroundA, i, 5 - i);
    std::cout << std::endl<< "Player B put your ships" << std::endl;
    for (int i = 1; i < 5; ++i)
        shipsPlacement(battlegroundB, i, 5 - i);

    std::cout << std::endl << std::endl << "Start" << std::endl;

    bool player = false;
    while (!isEmpty(battlegroundA) && !isEmpty(battlegroundB))
    {
        std::cout << std::endl << "Turn player " << (player ? "B" : "A") << std::endl;
        std::cout << "Input coordinates for shoot(A-J or a-j)(1-10): ";
        char x;
        int y;
        do
        {
            std::cin >> x >> y;
            if (x == '*') out((player) ? battlegroundA : battlegroundB);
            if (((x < 'A' || x > 'J') && (x < 'a' || x > 'j')) ||
                ((y < 1) || (y > 10)))
                std::cout << "Wrong input coordinates. Try again" << std::endl;
        } while (((x < 'A' || x > 'J') && (x < 'a' || x > 'j')) ||
                 ((y < 1) || (y > 10)));

        checkShot((player ? battlegroundA : battlegroundB), x, y - 1);
        player = !player;
    }

    std::cout << "Congratulation, Player " << (isEmpty(battlegroundA) ? "B" : "A") << " win";
}