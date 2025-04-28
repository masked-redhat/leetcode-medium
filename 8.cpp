#include <bits/stdc++.h>

using namespace std;

bool isNumber(char c)
{
    return c - '0' >= 0 && c - '0' < 10;
}

int myAtoi(string s)
{
    int i = 0, y = 0;

    // remove leading whitespace
    while (s[i] == ' ')
        i++;

    // check for sign
    bool neg = false;
    if (s[i] == '-' || s[i] == '+')
    {
        neg = s[i] == '-';
        i++;
    }

    // remove leading zeroes
    while (s[i] == '0')
        i++;

    // extract the number
    while (isNumber(s[i]) && i < s.length())
    {
        int num = s[i] - '0';
        if (!neg && (INT_MAX - num) / 10 < y)
        {
            y = INT_MAX;
            break;
        }
        if (neg && (INT_MIN + num) / 10 > y)
        {
            y = INT_MIN;
            break;
        }

        y = y * 10 + (neg ? -1 : 1) * num;
        i++;
    }

    return y;
}

int main()
{
    string num = "2147483641";

    cout << "Converted Integer : " << myAtoi(num) << endl;

    return 0;
}
