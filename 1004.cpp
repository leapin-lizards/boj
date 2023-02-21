#include <iostream>
using namespace std;
int pow(int n)
{
    return n * n;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x1, x2, y1, y2, n,count=0;
        int planets[3][50];
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> planets[0][j] >> planets[1][j] >> planets[2][j];
            int distX1 = planets[0][j] - x1, distY1 = planets[1][j] - y1;
            int distX2 = planets[0][j] - x2, distY2 = planets[1][j] - y2;
            int dist1 = pow(distX1) + pow(distY1);
            int dist2 = pow(distX2) + pow(distY2);
            if (dist1 > pow(planets[2][j])&&dist2 < pow(planets[2][j]))
            {
                count++;
            }
            else if(dist1 < pow(planets[2][j])&&dist2 > pow(planets[2][j]))
            {
                count++;
            }
        }
        cout<<count<<"\n";
    }
}