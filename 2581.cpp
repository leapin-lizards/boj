#include <iostream>
using namespace std;
bool isPrime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a,b,minPrime=-1,sum=0;
    cin>>a;
    cin>>b;
    for(int i=a;i<=b;i++)
    {
        if(i==1)
        {
            continue;
        }
        if(isPrime(i)&&minPrime==-1)
        {
            minPrime=i;
            sum+=i;
        }
        else if(isPrime(i))
        {
            sum+=i;
        }
    }
    if(minPrime==-1)
    {
        cout<<minPrime;
    }
    else
    {
        cout<<sum<<"\n";
        cout<<minPrime;
    }
}