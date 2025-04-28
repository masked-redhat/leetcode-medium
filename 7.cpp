#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    if (x == INT_MIN || x == INT_MAX)
        return 0;

    int y = 0;

    bool neg = false;
    if (x < 0)
    {
        neg = true;
        x = -1 * x;
    }

    while (x != 0)
    {
        int rem = x % 10;

        if ((INT_MAX - rem) / 10 < y)
            return 0;
        y = y * 10 + rem;

        x /= 10;
    }

    return (neg ? -1 : 1) * y;
}

int main()
{
    int x = 1463847412;

    cout << "Reversed Integer : " << reverse(x) << endl;

    return 0;
}
