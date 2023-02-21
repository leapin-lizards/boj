#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
            {
                cout << "-1\n";
                continue;
            }
            else
            {
                cout<<"0\n";
                continue;
            }
        }
        int distX=x1-x2,distY=y1-y2;
        int dist=distX*distX+distY*distY;
        if(dist==(r1+r2)*(r1+r2)||dist==abs(r1-r2)*abs(r1-r2))
        {
            cout<<"1\n";
        }
        else if(dist<(r1+r2)*(r1+r2)&&dist>abs(r1-r2)*abs(r1-r2))
        {
            cout<<"2\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
}