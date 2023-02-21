#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> coords;
    int minx = 99999, maxx = -999999, maxy = -99999, miny = 99999;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
        if (x > maxx)
        {
            maxx = x;
        }
        if (y > maxy)
        {
            maxy = y;
        }
        if (x < minx)
        {
            minx = x;
        }
        if (y < miny)
        {
            miny = y;
        }
    }
    if(n==2)
    {
        cout<<maxx - minx;
    }
    if (n >= 3)
    {
        if (maxx - minx != maxy - miny)
        {
            cout << "-1";
            return 0;
        }
        for (int i = 0; i < coords.size(); i++)
        {
            if (coords[i].first != maxx && coords[i].first != minx&&coords[i].second != maxy && coords[i].second != miny)
            {
                cout << "-1";
                return 0;
            }
        }
        cout<<maxx-minx;
    }
    return 0;
}