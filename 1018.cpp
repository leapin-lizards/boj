#include <iostream>
using namespace std;
int n, m, mat[50][50];
int check(int x, int y)
{
    int bw = 1, count1 = 0, count2 = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (mat[x + i][y + j] == bw)
            {
                count1++;
            }
            bw*=-1;
        }
        bw *= -1;
    }
    bw = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (mat[x + i][y + j] == bw)
            {
                count2++;
            }
            bw*=-1;
        }
        bw *= -1;
    }
    if(count1>count2)
    {
        return 64-count1;
    }
    else
    {
        return 64-count2;
    }
}
int main()
{

    cin >> n >> m;
    int min=999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char k;
            cin >> k;
            if (k == 'W')
                mat[i][j] = 1;
            else
                mat[i][j] = -1;
        }
    }

    for (int i = 0; i < n-7; i++)
    {
        for (int j = 0; j < m-7; j++)
        {
            if(min>check(i,j))
            {
                min=check(i,j);
            }
        }
    }
    cout<<min;
}