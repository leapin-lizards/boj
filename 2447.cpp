#include <stdio.h>
bool mat[7000][7000];
int coordx[] = {0, 1, 2, 0, 0, 1, 2, 2, 1};
int coordy[] = {0, 0, 0, 1, 2, 2, 1, 2, 1};
void recursion(int x, int y, int size)
{

    if (size == 3)
    {
        for (int i = 0; i < 8; i++)
        {
            mat[x + coordx[i]][y + coordy[i]] = true;
        }
        return;
    }
    for (int i = 0; i < 8; i++)
    {

        recursion(x + (size / 3) * coordx[i], y + (size / 3) * coordy[i], size / 3);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    recursion(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == true)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}