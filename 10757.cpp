#include <iostream>
#include <string>
using namespace std;
int ctoa(char k)
{
    return k - '0';
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    string str3;
    int la = str1.length(), lb = str2.length();
    int lm;
    if (la > lb)
    {
        lm = la;
        for (int i = 0; i < la - lb; i++)
        {
            str2.insert(0, "0");
        }
    }
    else
    {
        lm = lb;
        for (int i = 0; i < lb - la; i++)
        {
            str1.insert(0, "0");
        }
    }
    int carry = 0;
    for (int i = 0; i < lm; i++)
    {
        if (carry + ctoa(str1.at(lm - i - 1)) + ctoa(str2.at(lm - i - 1)) >= 10)
        {

            str3.insert(0, to_string(carry + ctoa(str1.at(lm - i - 1)) + ctoa(str2.at(lm - i - 1)) - 10));
            carry = 1;
        }
        else
        {
            str3.insert(0, to_string(carry + ctoa(str1.at(lm - i - 1)) + ctoa(str2.at(lm - i - 1))));
            carry = 0;
        }
    }
    if (carry == 1)
    {
        str3.insert(0, "1");
    }
    cout<<str3;
    return 0;
}