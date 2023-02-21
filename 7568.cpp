#include <iostream>
using namespace std;
int main()
{
    int n;
    int w[100],h[100],c[100]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(w[i]<w[j]&&h[i]<h[j])
            {
                c[i]++;
            }
        }
        cout<<++c[i]<<" ";
    }
}