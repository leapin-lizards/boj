#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        char str[1000];
        sprintf(str,"%d",i);
        for (int j = 0; j < strlen(str); j++)
        {
            sum += str[j] - '0';
        }
        if (sum + i == n)
        {
            cout << i;
            return 0;
        }
    }
    cout<<"0";
}