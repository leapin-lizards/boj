#include <iostream>
#include <vector>
using namespace std;
pair<int, int> reduce(int a, int b)
{
    bool c = true;
    while (c)
    {
        c = false;
        for (int i = 2; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                a /= i;
                b /= i;
                c = true;
                break;
            }
        }
    }
    return make_pair(a,b);
}
int main()
{
    int n;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        vec.push_back(inp);
    }
    for(int i=1;i<n;i++)
    {
        pair<int,int> res=reduce(vec[i],vec[0]);
        cout<<res.second<<"/"<<res.first<<"\n";
    }
}