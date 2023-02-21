#include <iostream>
#include <algorithm>
using namespace std;
int arr[500001],arr2[500000];
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    sort(arr,arr+n);
    for(int i=0;i<m;i++)
    {
        bool temp=true;
        cin>>arr2[i];
        int high=n-1;
        int low=0;
        while(high>=low)
        {
            int mid=(high+low)/2;
            if(arr[mid]==arr2[i])
            {
                temp=false;
                cout<<"1 ";
                break;
            }
            else if(arr[mid]>arr2[i])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(temp==true)
            cout<<"0 ";
    }
    return 0;
}