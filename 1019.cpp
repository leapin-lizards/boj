#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int cti(char c)
{
    return c - '0';
}
long long int intpow(long long int a, long long int b)
{
    long long int res = 1;
    for (long long int i = 0; i < b; i++)
    {
        if (res > 1e12)
        {
            return -2;
        }
        res *= a;
    }
    return res;
}
int countDigit(int n)
{
    return floor(log10(n) + 1);
}
int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
int combs(int a, int b)
{
    return (factorial(a) / factorial(b)) / factorial(a - b);
}
int calc(int digit)
{
    int sum = 0;
    for (int i = 1; i <= digit; i++)
    {
        sum += i * intpow(9, digit - i) * combs(digit, i);
        // if(i!=digit)
        //     sum-=i*intpow(9,digit-i-1)*combs(digit-1,i);
    }
    return sum;
}
int sub(int n)
{
    string str = to_string(n);
    str.erase(0, 1);
    while (str.at(0) == '0')
    {
        if(str.length()==1)
        {
            return 0;
        }
        str.erase(0, 1);

    }
    int ret = stoi(str);
    return ret;
}
int main()
{
    int input, len, res[10] = {0};
    cin >> input;
    string str = to_string(input);
    string str2=to_string(input);

    len = str.length();
    int len2=str.length();

    while (len >= 1)
    {
        if (len == 1)
        {
            for (int i = 1; i <= input; i++)
            {
                res[i]++;
            }
            break;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (i == 0)
                {
                    if(len2==str.length())
                    {
                        res[i]+=calc(len-1);
                        continue;
                    }
                    res[i] += calc(len - 1);
                    res[i] += calc(len - 1) * (cti(str[0]) - 1) + sub(input) + 1;
                }
                else if (i < cti(str[0])) // 1 _ _  ---- 8 _ _ ||9 _ _
                {
                    res[i] += calc(len - 1);
                    res[i] += calc(len - 1) * (cti(str[0]) - 1) + intpow(10, len - 1); // 20*8+100+1*8+10+1
                }
                else if (i == cti(str[0]))
                {
                    res[i] += calc(len - 1);
                    res[i] += calc(len - 1) * (cti(str[0]) - 1) + sub(input) + 1;
                }
                else if (i > cti(str[0]))
                {
                    res[i] += calc(len - 1);
                    res[i] += calc(len - 1) * (cti(str[0]) - 1);
                }
            }
        }
        input = sub(input);
        len = countDigit(input);
        str = to_string(input);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
