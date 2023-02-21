#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if(n==1)
        return false;
    int i=2;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            return false;
        }
        i++;
    }
    return true;
}
int primeTable[10000000];
int main()
{
    int n,front=0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            primeTable[front++]=i;
        }
    }
    while(n>1)
    {
        for(int i=0;i<front;i++)
        {
            if(n%primeTable[i]==0)
            {
                cout<<primeTable[i]<<"\n";
                n/=primeTable[i];
                break;
            }
        }
    }
}
