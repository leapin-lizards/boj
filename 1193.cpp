#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cv=1;
    int k=2;
    while(cv<n)
    {
        cv+=k;
        k++;
    }
    k--;
    if(k%2==0)
    {
        cout<<k-(cv-n)<<"/"<<1+(cv-n);
        return 0;
    }
    else
    {
        cout<<1+(cv-n)<<"/"<<k-(cv-n);
        return 0;
    }
}