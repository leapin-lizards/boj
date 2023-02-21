#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k=0;
    while(n>=0)
    {
        if(n%5==0)
        {
            cout<<n/5+k;
            return 0;
        }
        else
        {
            n-=3;
        }
        k++;
    }
    cout<<"-1";
}