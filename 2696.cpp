#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;
        cout << (m + 1) / 2;
        cout << "\n";

        vector<int> arr;
        for (int j = 1; j <= m; j++)
        {
            int k;
            cin >> k;
            arr.push_back(k);
            if(j%20==0)
            {
                cout<<"\n";
            }
            if (j % 2 == 0)
                continue;
            // cout << "array before sorting:";
            // for (int q=0; q < arr.size(); q++)
            // {
            //     cout << arr[q] << " ";
            // }
            // cout << "\n";
            sort(arr.begin(), arr.end());
            //cout<<arr.size();
            // cout << "array after sorting:";
            // for (int q=0; q < arr.size(); q++)
            // {
            //     cout << arr[q] << " ";
            // }
            // cout << "\n";
            if (arr.size() % 2 == 0)
            {
                cout << (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2<<" ";
            }
            else
            {
                cout << arr[(arr.size() + 1) / 2 - 1]<<" ";
            }
        }
    }
}