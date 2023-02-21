#include <iostream>
#include <vector>
using namespace std;
int map[8][8];
vector<pair<int, int>> coords;
vector<vector<int>> combs;
int arr[1000] = {0};
int originalMap[8][8];
int n, m;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
void output()
{
    vector<int> myVec;
    for (int i = 0; i < 3; i++)
    {
        myVec.push_back(arr[i]);
    }
    combs.push_back(myVec);
}
void choose(int level, int curr) // 1~(n-1)
{
    if (level == 3)
    {
        output();
        return;
    }
    for (int i = curr + 1; i <= coords.size(); i++)
    {
        arr[level] = i;
        choose(level + 1, i);
    }
}
bool oob(int i, int j)
{
    if (i < 0 || i >= n)
        return true;
    if (j < 0 || j >= m)
        return true;
    return false;
}
void flood(int i, int j)
{
    map[i][j] = 3;
    for (int k = 0; k < 4; k++)
    {
        if(oob(i+y[k],j+x[k]))
            continue;
        if(map[i+y[k]][j+x[k]]==1||map[i+y[k]][j+x[k]]==3)
            continue;
        flood(i + y[k], j + x[k]);
    }
}
int calc(int k)
{
    int count=0;
    for(int i=0;i<3;i++)
    {
        map[coords[combs[k][i]-1].first][coords[combs[k][i]-1].second]=1;
        // cout<<coords[combs[k][i]-1].first<<" "<<coords[combs[k][i]-1].second<<" has been blocked\n";
        // cout<<"testing::"<<combs[k][i]<<" "<<coords[combs[k][i]-1].first<<"\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j]==2)
                flood(i,j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j]==0)
                count++;
        }
    }
    return count;
}
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = originalMap[i][j];
        }
    }
}
int main()
{
    int max = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            originalMap[i][j] = map[i][j];
            if (map[i][j] == 0)
            {
                coords.push_back(make_pair(i, j));
            }
        }
    }
    choose(0, 0);
    // for(int i=0;i<combs.size();i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<combs[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for (int i = 0; i < combs.size(); i++)
    {
        int k = calc(i);
        // cout<<"===========\n";
        // for(int p=0;p<n;p++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<map[p][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (k > max)
        {
            max = k;
        }
        reset();
    }
    cout << max;
}