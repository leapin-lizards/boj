#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=666;
    while(n>0)
    {
        string str=to_string(i);
        if(str.find("666")!=string::npos)
        {
            n--;
        }
        i++;
    }
    cout<<i-1;
}