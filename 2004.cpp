#include <iostream>
using namespace std;
long long howMany2(long long n)
{
    long long count=0,i=2;
    while(i<=n)
    {
        count+=n/i;
        i*=2;
    }
    return count;
}
long long howMany5(long long n)
{
    long long count=0,i=5;
    while(i<=n)
    {
        count+=n/i;
        i*=5;
    }
    return count;
}
int main()
{
    long long n,m,numOf2=0,numOf5=0;
    cin>>n>>m;
    numOf2=howMany2(n)-howMany2(n-m)-howMany2(m);
    numOf5=howMany5(n)-howMany5(n-m)-howMany5(m);
    if(numOf2>numOf5)
    {
        cout<<numOf5;
    }
    else
    {
        cout<<numOf2;
    }

}