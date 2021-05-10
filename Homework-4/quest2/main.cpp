#include <iostream>
using namespace std;

char playField [3][3] = {'.', '.', '.',
                         '.', '.', '.',
                         '.', '.', '.'};

void input (char gameField [3][3], char symbol)
{
	int x, y;
	do
	{
		cout << endl <<"Player " << symbol << endl;
		cout << ". Write coordinate #1:";
		cin >> x;
        cout << ". Write coordinate #2:";
		cin >> y;
	} while ((gameField[x][y] != '.') || (x < 0 || x > 2) || (y < 0 || y > 2));

    gameField[x][y] = symbol;
}


void printed (char gameField [3][3])
{
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			cout << gameField[a][b] << " ";
		}
		cout << endl;
	}
}


bool win (char gameField[3][3])
{
	for (int b = 0; b < 3; ++b)
	{
		bool foundX = false;
		bool foundY = false;
		for (int a = 0; a < 2; ++a) {
            if ((gameField[b][a] == gameField[b][a + 1]) && (gameField[b][a] != '.') && foundX) {
                return true;
            } else {
                if ((gameField[b][a] == gameField[b][a + 1]) && (gameField[b][a] != '.')) {
                    foundX = true;
                }
            }
			if ((gameField[a][b] == gameField[a+1][b]) && (gameField[a][b] != '.') && foundY) {
                return true;
            } else {
                if ((gameField[a][b] == gameField[a + 1][b]) && (gameField[a][b] != '.')) {
                    foundY = true;
                }
            }
		}
	}

	bool foundXdiagonal = false;
	bool matchYdiagonal = false;
	for (int i = 0; i < 2; ++i)
	{
		if ((gameField[i][i] == gameField[i+1][i+1]) && (gameField[i][i] != '.') && foundXdiagonal) {
            return true;
        } else {
            if ((gameField[i][i] == gameField[i + 1][i + 1]) && (gameField[i][i] != '.')) {
                foundXdiagonal = true;
            }
        }
		if ((gameField[i][2-i] == gameField[i+1][2-(i+1)]) && (gameField[i][2-i] != '.') && matchYdiagonal) {
            return true;
        }else {
            if ((gameField[i][2 - i] == gameField[i + 1][2 - (i + 1)]) && (gameField[i][2 - i] != '.')) {
                matchYdiagonal = true;
            }
        }
	}
	return false;
}


int main()
{
	for (int turn = 1; (turn <= 9) && !(win(playField)); ++turn)
	{
		input (playField, ((turn % 2 == 0) ? 'X' : 'O'));
		printed (playField);
		if (win (playField))
			cout << endl << ((turn % 2 == 0) ? 'X' : 'O') << " - Win!";
	}

	if (!win(playField)){
        cout << endl << "Draw!" << endl;
	}
}