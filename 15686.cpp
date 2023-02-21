#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> init;
vector<int> combination;
vector<vector<int>> res;
vector<pair<int, int>> cLocs;
vector<pair<int, int>> hLocs;
int mask[50][50];
int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
void print()
{
    for (int i = 0; i < combination.size(); i++)
    {
        cout << combination[i] << " ";
    }
    cout << "\n";
}
void go(int offset, int k)
{
    if (k == 0)
    {
        res.push_back(combination);
        return;
    }
    for (int i = offset; i <= init.size() - k; i++)
    {
        combination.push_back(init[i]);
        go(i + 1, k - 1);
        combination.pop_back();
    }
}
int getDist(int k)
{
    int cDist=0;
    for (int i = 0; i < hLocs.size(); i++)
    {
        int min = 9999999;
        for (int j = 0; j < cLocs.size(); j++)
        {
            if (find(res[k].begin(), res[k].end(), mask[cLocs[j].first][cLocs[j].second]) != res[k].end())
            {
                if (dist(hLocs[i].first, hLocs[i].second, cLocs[j].first, cLocs[j].second) < min)
                {
                    min = dist(hLocs[i].first, hLocs[i].second, cLocs[j].first, cLocs[j].second);
                }
            }
        }
        cDist+=min;
    }
    return cDist;
}
int main()
{
    int n, m, map[50][50], cCount = 0, hCount = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                hCount++;
                hLocs.push_back(make_pair(i, j));
            }
            if (map[i][j] == 2)
            {
                mask[i][j] = cCount++;
                cLocs.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < cCount; i++)
    {
        init.push_back(i);
    }
    go(0, m);
    int min=9999999;
    for (int i = 0; i < res.size(); i++)
    {
        if(getDist(i)<min)
        {
            min=getDist(i);
        }
    }
    cout<<min;
}
