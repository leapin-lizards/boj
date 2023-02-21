#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a,b,v;
    cin>>a;
    cin>>b;
    cin>>v;
    int c=v-a;
    int k=ceil((double)c/(a-b));
    cout<<k+1;
}
