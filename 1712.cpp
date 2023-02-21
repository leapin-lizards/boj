#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    if(b>=c)
    {
        cout<<"-1";
        return 0;
    }
    cout<<a/(c-b)+1;
}