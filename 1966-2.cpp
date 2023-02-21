#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> q;
void pushQ(int n, int l)
{
    pair<int, int> temp;
    temp = make_pair(n, l);
    q.push_back(temp);
}
pair<int, int> popQ()
{
    pair<int, int> ret = q[0];
    q.erase(q.begin());
    return ret;
}
void pushFront(pair<int, int> inp)
{
    q.insert(q.begin(), inp);
}
bool checkPrio(pair<int, int> inp)
{
    for (int i = 0; i < q.size() - 1; i++)
    {
        if (q[i].first > inp.first)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, l;
        q.clear();
        cin >> n >> l;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            pushFront(make_pair(temp, j));
        }
        int count = 1;
        while (1)
        {
            if (checkPrio(q.back()))
            {
                if (q.back().second == l)
                {
                    cout << count << "\n";
                    break;
                }
                else
                {
                    q.pop_back();
                    count++;
                }
            }
            else
            {
                pushFront(q.back());
                q.pop_back();
            }
        }
    }
}