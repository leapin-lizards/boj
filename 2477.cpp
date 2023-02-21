#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int coord[6][2];
    int lens[6];
    cin>>n;
    coord[0][0]=0;
    coord[0][1]=0;
    int x=0,y=0;
    for(int i=1;i<6;i++)
    {
        int dir,len;
        cin>>dir;
        cin>>len;
        lens[i-1]=len;
        if(dir==1)
        {
            x+=len;
        }
        else if(dir==2)
        {
            x-=len;
        }
        else if(dir==3)
        {
            y-=len;
        }
        else if(dir==4)
        {
            y+=len;
        }
        coord[i][0]=x;
        coord[i][1]=y;
    }
    int trash1,trash2;
    cin>>trash1;
    cin>>trash2;
    lens[5]=trash2;
    int minx=10000;
    int maxx=-1;
    for(int i=0;i<6;i++)
    {
        if(coord[i][0]>maxx)
        {
            maxx=coord[i][0];
        }
        if(coord[i][0]<minx)
        {
            minx=coord[i][0];
        }        
    }
    int miny=10000;
    int maxy=-1;
    for(int i=0;i<6;i++)
    {
        if(coord[i][1]>maxy)
        {
            maxy=coord[i][1];
        }
        if(coord[i][1]<miny)
        {
            miny=coord[i][1];
        }        
    }
    int loc;
    for(int i=0;i<6;i++)
    {
        if(coord[i][0]!=maxx&&coord[i][0]!=minx&&coord[i][1]!=maxy&&coord[i][1]!=miny)
        {
            loc=i;
        }
    }
    int dx=maxx-minx,dy=maxy-miny;
    int a1=dx*dy;
    int a2;
    if(loc==0)
    {
        a2=lens[0]*lens[5];
    }
    else
    {
        a2=lens[loc]*lens[loc-1];
    }
    cout<<n*(a1-a2);
    return 0;
}