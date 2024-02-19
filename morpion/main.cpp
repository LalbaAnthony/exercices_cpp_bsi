#include <iostream>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <cctype>

using namespace std;

void putInGrid(char grid[3][3], char c, int x, int y)
{
    grid[x][y] = c;
}

void playRandom(char grid[3][3], char c)
{
    int x, y;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while(grid[x][y] != ' ');
    putInGrid(grid, c, x, y);
}

void clearGrid(char grid[3][3])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            grid[i][j] = ' ';
}

void printGrid(char grid[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << '[' << grid[i][j] << ']' << (j == 2 ? '\n' : ' ');
        }
    }
}

bool checkWin(char grid[3][3], char charToCheck = 'X')
{
    for(int i = 0; i < 3; i++)
    {
        if(grid[i][0] == charToCheck && grid[i][1] == charToCheck && grid[i][2] == charToCheck)
            return true;
        if(grid[0][i] == charToCheck && grid[1][i] == charToCheck && grid[2][i] == charToCheck)
            return true;
    }
    if(grid[0][0] == charToCheck && grid[1][1] == charToCheck && grid[2][2] == charToCheck)
        return true;
    if(grid[0][2] == charToCheck && grid[1][1] == charToCheck && grid[2][0] == charToCheck)
        return true;
    return false;
}

int main()
{
    char grid[3][3];

    srand(time(NULL));

    clearGrid(grid);

    while(true)
    {
        printGrid(grid);
        int x, y;
        cout << "Enter the coordinates of your move (x): ";
        cin >> x;
        cout << "Enter the coordinates of your move (y): ";
        cin >> y;
        x--; y--;
        if(x < 0 || x > 2 || y < 0 || y > 2 || grid[x][y] != ' ')
        {
            cout << "Invalid move!" << endl;
            continue;
        }
        putInGrid(grid, 'X', x, y);
        if(checkWin(grid, 'X'))
        {
            printGrid(grid);
            cout << "You win!" << endl;
            break;
        }
        bool full = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(grid[i][j] == ' ')
                    full = false;
        if(full)
        {
            printGrid(grid);
            cout << "It's a draw!" << endl;
            break;
        }
        playRandom(grid, 'O');
        if(checkWin(grid, 'O'))
        {
            printGrid(grid);
            cout << "You lose!" << endl;
            break;
        }
    }

    return 0;
}
