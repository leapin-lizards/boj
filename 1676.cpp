#include <iostream>
using namespace std;
int howMany2(int n)
{
    int count=0;
    while(n%2==0)
    {
        count++;
        n/=2;
    }
    return count;
}
int howMany5(int n)
{
    int count=0;
    while(n%5==0)
    {
        count++;
        n/=5;
    }
    return count;
}
int main()
{
    int n,numOf2=0,numOf5=0;
    cin>>n;
    if(n==0||n==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        numOf2+=howMany2(i);
        numOf5+=howMany5(i);
    }
    if(numOf2>numOf5)
    {
        cout<<numOf5;
    }
    else
    {
        cout<<numOf2;
    }
}