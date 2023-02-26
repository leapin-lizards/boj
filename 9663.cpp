#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n;
int res = 0;
int arr[14][14] = {0};
bool check(int i, int j, vector<pair<int, int>> visit)
{
    for (int k = 0; k < visit.size(); k++)
    {
        if (i == visit[k].first || j == visit[k].second)
            return false;
        if (abs(i - visit[k].first) == abs(j - visit[k].second))
            return false;
    }
    return true;
}
void dfs(int *cols, int *negDiag, int *posDiag, int row)
{
    if (row == n)
    {
        res++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (cols[i] == 0)
        {
            if (negDiag[i - row+1000] == 0)
            {
                if (posDiag[i + row] == 0)
                {
                    cols[i]=1;
                    negDiag[i-row+1000]=1;
                    posDiag[i+row]=1;
                    dfs(cols, negDiag, posDiag, row + 1);
                    cols[i]=0;
                    negDiag[i-row+1000]=0;
                    posDiag[i+row]=0;
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cols[100] = {0};
        cols[i] = 1;
        int negDiag[10000] = {0};
        negDiag[i+1000] = 1;
        int posDiag[10000] = {0};
        posDiag[i] = 1;
        dfs(cols, negDiag, posDiag, 1);
    }

    cout << res;
}