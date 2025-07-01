#include <bits/stdc++.h>

using namespace std;

int possibleStringCount(string word)
{
    int sum = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (i < word.length() && word[i + 1] == word[i])
            sum++;
    }
    return 1 + sum;
}

int main()
{
    string word = "abbc";

    cout << "Possible count : " << possibleStringCount(word) << endl;

    return 0;
}
