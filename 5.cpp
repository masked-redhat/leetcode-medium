#include <bits/stdc++.h>

using namespace std;

string palindromeFrom(string &s, int left, int right)
{
    string palindrome = "";
    palindrome += s[left];

    if (s[left] != s[right])
        return palindrome;

    while (left >= 0 && right < s.length())
    {
        if (s[left] == s[right])
        {
            left--;
            right++;
        }
        else
            break;
    }

    if (left < 0 || right >= s.length() || s[left] != s[right])
    {
        left++;
        right--;
    }

    palindrome = s.substr(left, right - left + 1);
    return palindrome;
}

string longestPalindrome(string s)
{
    string result;
    int stringLen = s.length();

    if (stringLen == 1)
    {
        result += s[0];
        return result;
    }

    for (int i = 0; i < stringLen; i++)
    {
        string pal1 = palindromeFrom(s, i, i);
        if (i + 1 < stringLen)
        {
            string pal2 = palindromeFrom(s, i, i + 1);
            if (pal1.length() < pal2.length())
                pal1 = pal2;
        }

        if (result.length() < pal1.length())
            result = pal1;
    }

    return result;
}

int main()
{
    string s = "cddddasdewasdkjfowfwonwqod";

    cout << "Longest palindrome: " << longestPalindrome(s) << endl;

    return 0;
}
