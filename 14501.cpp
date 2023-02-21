#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxF(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n;
    int val[15][2];
    int d[15], max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        val[i][0] = t;
        val[i][1] = p;
    }
    for (int i = 0; i < n; i++)
    {
        if (val[i][0] + i > n)
        {
            d[i] = -999999;
            continue;
        }
        vector<int> p;
        for (int j = 0; j < i; j++)
        {
            if (val[j][0] + j == i)
            {
                p.push_back(d[j]);
            }
        }
        if (p.empty())
        {
            int localMax = 0;
            for (int j = 0; j < i; j++)
            {
                if (d[j] > localMax && val[j][0] < i - j)
                {
                    localMax = d[j];
                }
            }
            d[i] = localMax + val[i][1];
            continue;
        }
        else
        {
            int localMax = 0;
            for (int j = 0; j < i; j++)
            {
                if (d[j] > localMax && val[j][0] < i - j)
                {
                    localMax = d[j];
                }
            }
            d[i] = val[i][1]+(maxF(localMax,*max_element(p.begin(), p.end())));
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
    cout << max;
}