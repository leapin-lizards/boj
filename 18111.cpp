#include <iostream>
using namespace std;
int mat[500][500];

int n, m, inv;
int calcTime(int k)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > k)
            {
                time += 2 * (mat[i][j] - k);
            }
            if (mat[i][j] < k)
            {
                time += k - mat[i][j];
            }
        }
    }
    return time;
}
int main()
{
    int min1 = -1, max1 = 99999;
    cin >> n >> m >> inv;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] > max1)
            {
                max1 = mat[i][j];
            }
            if (mat[i][j] < min1)
            {
                min1 = mat[i][j];
            }
        }
    }
    int minTime = 99999999;
    int level;
    for (int i = min1; i <= max1; i++)
    {
        int temp = calcTime(i);
        if (temp < minTime)
        {
            minTime = temp;
            level=i;
        }
    }
    cout << minTime<<" "<<level;
}