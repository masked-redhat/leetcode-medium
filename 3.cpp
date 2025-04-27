#include <bits/stdc++.h>

using namespace std;

bool isOdd(int value)
{
    return value % 2 == 1;
}

bool isEven(int value)
{
    return value % 2 == 0;
}

bool isCharPresent(unordered_map<char, int> &charMap, char c)
{
    if (charMap.find(c) == charMap.end())
        return false;

    return true;
}

void printCharMap(unordered_map<char, int> &charMap)
{
    for (auto x : charMap)
        cout << x.first << " " << x.second << endl;
}

int getMaxSubstringLength(string &s)
{
    unordered_map<char, int> charMap;

    for (auto x : s)
        charMap[x] = 0;

    return charMap.size();
}

int lengthOfLongestSubstring(string s)
{
    int maxLength = getMaxSubstringLength(s);

    // if its 0 or 1 then that's the longest
    if (maxLength < 2)
        return maxLength;

    int currMaxLength = 0;

    unordered_map<char, int> charMapInSlide;

    int start = 0, end = 0;

    while (end < s.length())
    {
        while (end - start < maxLength && end < s.length())
        {
            char letter = s[end];
            int value = charMapInSlide[letter];

            if (isOdd(value))
                break;

            end++;
            charMapInSlide[letter]++;
        }

        int currLength = end - start;
        currMaxLength = max(currMaxLength, currLength);
        if(currMaxLength == maxLength) return maxLength;

        charMapInSlide[s[start]]--;
        start++;
    }

    return currMaxLength;
}

int main()
{
    string s = "pwwkew";
    cout << "Longest substring in s : " << lengthOfLongestSubstring(s) << endl;

    return 0;
}
