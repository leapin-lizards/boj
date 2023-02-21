#include <iostream>
#include <iomanip>
const double PI = 3.1415926535897932384626433832795028841971693993751058209;
using namespace std;
int main()
{
    int n;
    cin>>n;
    double res=((double)n*(double)n)*PI;
    cout<<fixed;
    cout.precision(6);
    cout<<res<<"\n";
    cout<<n*n*2;
}