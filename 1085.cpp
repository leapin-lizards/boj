#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int minx,miny;
    minx=x>w-x? w-x:x;
    miny=y>h-y?h-y:y;
    int res=(minx>miny)?miny:minx;
    cout<<res;
}