#include <iostream>
#include <ctime>
using namespace std;

const unsigned int DS = 8;
int Desk[DS][DS];
int Step[8][2] = {{1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};
int N;

bool Set_Horse(int x, int y)
{
    if ((x < 0) || (x >= DS) || (y < 0) || (y >= DS))
        return false;

    if (Desk[x][y] != 0)
        return false;

    N++;
    Desk[x][y] = N;

    if (N == DS * DS)
        return true;

    for (int i = 0; i < 8; i++)
        if (Set_Horse(x + Step[i][0], y + Step[i][1]))
            return true;

    N--;
    Desk[x][y] = 0;
    return false;
}

void Print_Desk()
{
    for (int i = 0; i < DS; i++)
    {
        for (int j = 0; j < DS; j++)
            cout << Desk[i][j] << "|";
        cout << endl;
    }
}

int main()
{
    time_t t_start, t_end;
    setlocale(LC_ALL, "Rus");
    time(&t_start);
    N = 0;
    for (int i = 0; i < DS; i++)
        for (int j = 0; j < DS; j++)
            Desk[i][j] = 0;
    Set_Horse(1,1);
    Print_Desk();
    time(&t_end);
    cout << endl << "Решение найдено за " << t_end - t_start << " секунд" << endl;
}
