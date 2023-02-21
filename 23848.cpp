#include <iostream>
#include <cmath>
using namespace std;
long long int intpow(long long int a,long long int b)
{
    long long int res=1;
    for(long long int i=0;i<b;i++)
    {
        if(res>1e12)
        {
            return -2;
        }
        res*=a;
    }
    return res;
}
long long int sigma(long long int r,long long int n)
{
    long long int a=intpow(r,n);
    if(a==-2)
    {
        return -2;
    }
    a=a-1;
    long long int b=r-1;
    return a/b;
}
void print(long long int a,long long int r,long long int n)
{
    long long int ak=a;
    for(long long int i=0;i<n;i++)
    {
        cout<<ak<<" ";
        ak*=r;
    }
}
int main()
{
    long long int n;
    cin>>n;

    for(long long int i=2;i<n&&i<1000000;i++)
    {
        for(long long int j=3;j<n/i+1&&j<40;j++)
        {
            long long int k=sigma(i,j);
            if(k>n||k==-2)
            {
                break;
            }
            if(n%k==0)
            {
                print((n/k),i,j);
                return 0;
            }
        }
    }
    cout<<"-1";
    return 0;
}