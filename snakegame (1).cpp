#include <iostream>
#include <conio.h>
using namespace std;
const int width = 50;
const int height = 50;
bool gameOver;
int x, y, fX, fY, score;
int tailX[200], tailY[200], nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fX = rand() % width;
    fY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fY && j == fX)
            {
                cout << "F";
            }
            else
            {
                for (int k = 0; k < nTail; k++)
                {
                    if (tailY[k] == i && tailX[k] == j)
                    {
                        cout << "o";
                    }
                }
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score : " << score;
}
void Input()
{
    if (_kbhit())
    {
        switch (getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 'z':
            dir = DOWN;
            break;
        default:
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailY[0] = y;
    tailX[0] = x;
    for (int i = 1; i < nTail; i++)
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
    }
    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = true;
    }
    if (x == fX && y == fY)
    {
        score += 10;
        fX = rand() % width;
        fY = rand() % height;
        nTail++;
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
}