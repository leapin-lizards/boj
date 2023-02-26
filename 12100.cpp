#include <iostream>
#include <vector>
using namespace std;
int n;
int map[21][21];
int originalMap[21][21];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<vector<int>> moves;
void combinations()
{
    for (int i = 0; i < 1024; i++)
    {
        vector<int> temp;
        temp.push_back((int)(i / 256) % 4);
        temp.push_back((int)(i / 64) % 4);
        temp.push_back((int)(i / 16) % 4);
        temp.push_back((int)(i / 4) % 4);
        temp.push_back((int)(i % 4));
        // cout<<"i::"<<i<<"   ";
        // for (int j = 0; j < 5; j++)
        // {
        //     cout << temp[j] << " ";
        // }
        // cout << "\n";
        moves.push_back(temp);
    }
}
pair<int, int> look(int dir, int y, int x)
{
    int ty = y;
    int tx = x;
    while (1)
    {
        ty += dy[dir];
        tx += dx[dir];
        if (ty >= n || tx >= n || ty < 0 || tx < 0)
            break;

        if (map[ty][tx] == map[y][x])
        {
            return make_pair(ty, tx);
        }
        else if(map[ty][tx]!=0)
        {
            break;
        }
    }
    return make_pair(-1, -1);
}
void shift(int dir)
{
    vector<int> q;
    if (dir == 0)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (map[i][j] != 0)
                {
                    q.push_back(map[i][j]);
                    map[i][j]=0;
                }
            }
            for(int i=0;i<q.size();i++)
            {
                map[i][j]=q[i];
            }
            q.clear();
        }
    }
    if (dir == 1)
    {
        for (int j = 0; j < n; j++)
        {
            int count=0;
            for (int i = n-1; i >= 0; i--)
            {
                if (map[i][j] != 0)
                {
                    q.push_back(map[i][j]);
                    count++;
                    map[i][j]=0;
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                if(q.empty())
                    break;
                    
                map[i][j]=q.front();
                q.erase(q.begin());
            }
            q.clear();
        }
    }
    if (dir == 2)
    {
        for (int i = 0; i < n; i++)
        {
            int count=0;
            for (int j = n-1; j >= 0; j--)
            {
                if (map[i][j] != 0)
                {
                    q.push_back(map[i][j]);
                    count++;
                    map[i][j]=0;
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(q.empty())
                    break;

                map[i][j]=q.front();
                q.erase(q.begin());
            }
            q.clear();
        }
    }
    if (dir == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] != 0)
                {
                    q.push_back(map[i][j]);
                    map[i][j]=0;
                }
            }
            for(int j=0;j<q.size();j++)
            {
                map[i][j]=q[j];
            }
            q.clear();
        }
    }
}
void print()
{
    cout<<"===========\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void search(int dir, int y, int x)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (map[y+dy[dir]*i][x+dx[dir]*i] != 0)
        {
            pair<int, int> resault = look(dir, y+dy[dir]*i, x+dx[dir]*i);
            if (resault.first == -1)
                continue;
            else
            {
                map[y+dy[dir]*i][x+dx[dir]*i] += map[resault.first][resault.second];
                map[resault.first][resault.second] = 0;
            }
        }
    }
    shift(dir);
}
void play(int dir)
{
    if (dir == 0)
    {
        for (int i = 0; i < n; i++)
        {
            search(dir, 0, i);
        }
    }
    if (dir == 1)
    {
        for (int i = 0; i < n; i++)
        {
            search(dir, n - 1, i);
        }
    }
    if (dir == 2)
    {
        for (int i = 0; i < n; i++)
        {
            search(dir, i, n-1);
        }
    }
    if (dir == 3)
    {
        for (int i = 0; i < n; i++)
        {
            search(dir, i, 0);
        }
    }
}
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = originalMap[i][j];
        }
    }
}
int calc()
{
    int max=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j]>max)
                max=map[i][j];
        }
    }
    return max;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            originalMap[i][j] = map[i][j];
        }
    }
    combinations();
    int max=0;
    for (int i = 0; i < 1024; i++)
    {
    //     if(moves[i][0]==0&&moves[i][1]==2&&moves[i][2]==2&&moves[i][3]==0&&moves[i][4]==2)
    //     {
    //         cout<<"here"<<i<<"\n";
    //     }
        for (int j = 0; j < 5; j++)
        {
            play(moves[i][j]);
            //print();
        }
        if(calc()>max)
            max=calc();
        reset();
    }
    cout<<max;
}