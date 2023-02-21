#include <iostream>
#include <math.h>
using namespace std;
 
void towerOfHanoi(int n,int from,int to,int aux)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout<<from<<" "<<to<<"\n";
    towerOfHanoi(n - 1, aux, to, from);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",((int)pow(2,n)-1));
    towerOfHanoi(n,1,3,2);
    return 0;
}
 