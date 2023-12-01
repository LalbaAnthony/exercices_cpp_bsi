#include <iostream>
#include <conio.h>  // For _getch()
#include <vector>
#include <cstdlib>   // For rand()

using namespace std;

const int width = 20;
const int height = 10;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake
{
private:
    vector<int> tailX, tailY;
    int length;
    int x, y;
    int fruitX, fruitY;
    Direction dir;
    bool gameOver;

public:
    Snake() : length(1), x(width / 2), y(height / 2), dir(STOP), gameOver(false)
    {
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                    cout << "#";  // left wall

                if (i == y && j == x)
                    cout << "O";  // snake head
                else if (i == fruitY && j == fruitX)
                    cout << "F";  // fruit
                else
                {
                    bool printTail = false;
                    for (int k = 0; k < length; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";  // snake tail
                            printTail = true;
                        }
                    }

                    if (!printTail)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#";  // right wall
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
    }

    void Input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void Logic()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;

        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < length; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        if (x >= width) x = 0;
        else if (x < 0) x = width - 1;

        if (y >= height) y = 0;
        else if (y < 0) y = height - 1;

        for (int i = 0; i < length; i++)
        {
            if (tailX[i] == x && tailY[i] == y)
            {
                gameOver = true;
            }
        }

        if (x == fruitX && y == fruitY)
        {
            length++;
            fruitX = rand() % width;
            fruitY = rand() % height;
        }
    }

    bool GameOver()
    {
        return gameOver;
    }
};

int main()
{
    Snake snake;

    while (!snake.GameOver())
    {
        snake.Draw();
        snake.Input();
        snake.Logic();
    }

    cout << "Game Over!" << endl;

    return 0;
}
