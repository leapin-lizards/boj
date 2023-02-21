#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int d;
    cin >> d;
    for (int k = 0; k < d; k++)
    {
        int h, w, n, x = 0, y = 0, layer = 1;
        cin >> h;
        cin >> w;
        cin >> n;
        double col=ceil((double)n/h);
        int row=n%h;
        if(row==0)
            row=h;
        cout<<row;
        if(col>=10)
            cout<<col<<"\n";
        else
            cout<<"0"<<col<<"\n";
    }
    return 0;
}