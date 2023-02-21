#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int wi=1;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    while(n-1>wi*(3*wi+3))
    {
        wi++;
    }
    cout<<wi+1;
    return 0;
}