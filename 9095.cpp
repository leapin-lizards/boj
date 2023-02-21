#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, arr[11];
        cin >> n;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        cout << arr[n]<<"\n";
    }
}