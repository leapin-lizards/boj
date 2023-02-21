#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int cloud[51][51];
int a[51][51];
vector<pair<int, int>> moves;
vector<pair<int, int>> dirs;
int n, m;
void formCloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
            {
                cloud[i][j] = 0;
                continue;
            }
            if (a[i][j] >= 2)
            {
                a[i][j] -= 2;
                cloud[i][j] = 1;
            }
        }
    }
}
bool boundary(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n)
        return false;
    else
        return true;
}
void rain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] += cloud[i][j];
        }
    }
}
void flow()
{
    vector<pair<int,int>> mods;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
            {
                for (int k = 1; k <= 7; k += 2)
                {
                    if (boundary(i + dirs[k].first, j + dirs[k].second) && a[i + dirs[k].first][j + dirs[k].second] >= 1)
                    {
                        mods.push_back(make_pair(i ,j));
                    }
                }
            }
        }
    }
    for(int i=0;i<mods.size();i++)
    {
        a[mods[i].first][mods[i].second]++;
    }
}
void moveCloud(pair<int, int> dir)
{
    int d = dir.first;
    int s = dir.second;
    int newCloud[51][51];
    int ki, kj;
    ki = dirs[d - 1].first * s;
    kj = dirs[d - 1].second * s;
    ki = ki % n;
    kj = kj % n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ni=i;
            int nj=j;
            for(int k=0;k<s;k++)
            {
                if(ki>0)
                    ni++;
                if(ki<0)
                    ni--;
                if(ni>n)
                    ni=1;
                if(ni<1)
                    ni=n;
                if(kj>0)
                    nj++;
                if(kj<0)
                    nj--;
                if(nj>n)
                    nj=1;
                if(nj<1)
                    nj=n;                
            }
            newCloud[ni][nj] = cloud[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cloud[i][j] = newCloud[i][j];
        }
    }
}
int main()
{
    dirs.push_back(make_pair(0, -1));
    dirs.push_back(make_pair(-1, -1));
    dirs.push_back(make_pair(-1, 0));
    dirs.push_back(make_pair(-1, 1));
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(1, 1));
    dirs.push_back(make_pair(1, 0));
    dirs.push_back(make_pair(1, -1));

    int res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int input;
            cin >> input;
            a[i][j] = input;
            ;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;
        moves.push_back(make_pair(d, s));
    }
    cloud[n][1] = 1;
    cloud[n - 1][1] = 1;
    cloud[n][2] = 1;
    cloud[n - 1][2] = 1;

    for (int q = 0; q < m; q++)
    {
        moveCloud(moves[q]);
        rain();
        flow();
        formCloud();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            res += a[i][j];
        }
    }
    cout << res;
}