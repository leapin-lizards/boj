#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n;
        vector<string> category;
        vector<int> count;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            string tempCategory;
            string name;
            cin>>name;
            cin>>tempCategory;
            auto iter=find(category.begin(),category.end(),tempCategory);
            if(iter==category.end())
            {
                count.push_back(1);
                category.push_back(tempCategory);
            }
            else
            {
                count[iter-category.begin()]++;
            }
        }
        int resault=1;
        for(int j=0;j<count.size();j++)
        {
            resault*=(count[j]+1);
        }
        cout<<resault-1<<"\n";
    }
}