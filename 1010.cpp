#include <iostream>
using namespace std;
unsigned long long combination(int n,int r)
{
    unsigned long long res = 1;
    for (int i = n; i >=n-r+1 ; i--)
    {
        res *= i;

        if(1+(n-i)>1)
            res/=1+(n-i);
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,r;
        cin>>r>>n;
        cout<<combination(n,r)<<"\n";
    }
}