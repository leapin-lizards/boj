#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dirs;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int map[10][10];
int originalMap[10][10];
int limit = 0;
void print()
{
    //cout<<"=================\n";
    // for (int p = 0; p < n; p++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << map[p][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
bool ob(int i, int j)
{
    if (i < 0)
        return false;
    if (j < 0)
        return false;
    if (i >= n)
        return false;
    if (j >= m)
        return false;
    return true;
}
void gen(vector<int> vec)
{
    while (1)
    {
        dirs.push_back(vec);
        vec.back()++;
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(vec[i]==5)
            {
                if(i==0)
                    return;

                vec[i]=1;
                vec[i-1]++;
            }
        }

    }
}
void resetmap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = originalMap[i][j];
        }
    }
}
int mov(int k, int i, int j)
{
    int kj = j, ki = i;
    int count = 0;
    while (1)
    {
        ki += dy[k - 1];
        kj += dx[k - 1];

        if (map[ki][kj] == 6 || !ob(ki, kj))
            break;

        if (map[ki][kj] != 0)
            continue;
        count++;
        map[ki][kj] = 7;
    }
    return count;
}

int calc(int k)
{
    int conv = 0;
    int camNo = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                continue;

            if (map[i][j] == 1)
            {
                conv += mov(dirs[k][camNo], i, j);
                print();
                camNo++;
            }
            if (map[i][j] == 2)
            {
                if (dirs[k][camNo] == 1 || dirs[k][camNo] == 2)
                {
                    conv += mov(1, i, j);
                    conv += mov(3, i, j);
                }
                if (dirs[k][camNo] == 3 || dirs[k][camNo] == 4)
                {
                    conv += mov(2, i, j);
                    conv += mov(4, i, j);
                }
                print();
                camNo++;
            }
            if (map[i][j] == 3)
            {
                if (dirs[k][camNo] == 1)
                {
                    conv += mov(1, i, j);
                    conv += mov(2, i, j);
                }
                if (dirs[k][camNo] == 2)
                {
                    conv += mov(1, i, j);
                    conv += mov(4, i, j);
                }
                if (dirs[k][camNo] == 3)
                {
                    conv += mov(2, i, j);
                    conv += mov(3, i, j);
                }
                if (dirs[k][camNo] == 4)
                {
                    conv += mov(3, i, j);
                    conv += mov(4, i, j);
                }
                print();
                camNo++;
            }
            if (map[i][j] == 4)
            {
                if (dirs[k][camNo] == 1)
                {
                    conv += mov(1, i, j);
                    conv += mov(2, i, j);
                    conv += mov(3, i, j);
                }
                if (dirs[k][camNo] == 2)
                {
                    conv += mov(1, i, j);
                    conv += mov(2, i, j);
                    conv += mov(4, i, j);
                }
                if (dirs[k][camNo] == 3)
                {

                    conv += mov(1, i, j);
                    conv += mov(3, i, j);
                    conv += mov(4, i, j);
                }
                if (dirs[k][camNo] == 4)
                {
                    conv += mov(2, i, j);
                    conv += mov(3, i, j);
                    conv += mov(4, i, j);
                }
                print();
                camNo++;
            }
            if (map[i][j] == 5)
            {
                for (int l = 0; l < 4; l++)
                {
                    conv += mov(l + 1, i, j);
                }
                print();
                camNo++;
            }
        }
    }
    return conv;
}
int main()
{
    int numOf0 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            originalMap[i][j] = map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6)
            {
                limit++;
            }
            if (map[i][j] == 0)
                numOf0++;
        }
    }
    if (numOf0 == 0)
    {
        cout << "0";
        return 0;
    }
    if (limit != 0)
    {
        vector<int> start;
        for (int i = 0; i < limit; i++)
        {
            start.push_back(1);
        }
    }
    else
    {
        cout << numOf0;
        return 0;
    }

    vector<int> start;
    for (int i = 0; i < limit; i++)
    {
        start.push_back(1);
    }
    int max = 0;
    gen(start);
    
//4,(4,3,2),1,(4,1),(1,3)

    // for (int i = 0; i < dirs.size(); i++)
    // {
    //     if(dirs[i][0]==4&&dirs[i][1]==4&&dirs[i][2]==1&&dirs[i][3]==2&&dirs[i][4]==2)
    //     {
    //         cout<<"#of dir of interest::"<<i<<"\n";
    //     }
    //     for (int j = 0; j < dirs[i].size(); j++)
    //     {
    //         cout << dirs[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < dirs.size(); i++)
    {
        int temp = calc(i);
        if (map[5][1] == 7)
        {
            // cout << "==========\n";
            // for (int p = 0; p < n; p++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << map[p][j] << " ";
            //     }
            //     cout << "\n";
            // }
        }
        if (temp > max)
        {
            max = temp;
            print();
        }
        resetmap();
    }
    cout << numOf0 - max;
}
