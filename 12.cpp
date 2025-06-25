#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
    const map<int, char>
        chart{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    string roman;

    int place = 1;
    while (num > 0)
    {
        string add_str;
        int focus_num = (num % 10);

        if (focus_num == 4 || focus_num == 9)
        {
            add_str += chart.at(place);
            add_str += chart.at(place + (focus_num * place));
        }
        else
        {
            focus_num *= place;

            for (auto it = chart.rbegin(); it != chart.rend(); it++)
            {
                if (it->first > focus_num)
                    continue;

                while (focus_num >= it->first)
                {
                    add_str += it->second;
                    focus_num -= it->first;
                }
            }
        }

        roman = add_str + roman;
        num /= 10;
        place *= 10;
    }

    return roman;
}

int main()
{
    int num = 3849;

    cout << num << " : " << intToRoman(num) << endl;

    return 0;
}
