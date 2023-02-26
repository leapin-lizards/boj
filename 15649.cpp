#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
void print(vector<int> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << "\n";
}
void comb(int pos, int k, vector<int> in)
{
    in.push_back(k);
    if (pos == m-1)
    {
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(in.begin(), in.end(), i) == in.end())
        {
            comb(pos + 1, i, in);
        }
    }
}
int main()
{
    int buffer[9];

    cin >> n >> m;
    vector<int> vec;
    for(int i=1;i<=n;i++)
    {
        comb(0,i,vec);
    }
}