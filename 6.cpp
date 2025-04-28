#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows)
{
    if (s.length() <= numRows || numRows < 2)
        return s;

    int midNums = numRows - 2;
    int addNum = numRows + midNums;

    string zzstr = "";

    for (int i = 0; i < numRows; i++)
    {
        int j = i;
        for (; j < s.length(); j += addNum)
        {
            int newCharLoc = j - i * 2;
            if (newCharLoc >= 0 && j != newCharLoc && newCharLoc != j - addNum)
                zzstr += s[newCharLoc];

            zzstr += s[j];
        }

        int newCharLoc = j - i * 2;
        if (newCharLoc >= 0 && newCharLoc < s.length() && j != newCharLoc && newCharLoc != j - addNum)
            zzstr += s[newCharLoc];
    }

    return zzstr;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << "Converted string: " << convert(s, numRows) << endl;

    return 0;
}
