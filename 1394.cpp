#include <bits/stdc++.h>

using namespace std;

int luckyNum(vector<int> &arr)
{
    map<int, int> chart;
    for (auto i : arr)
        chart[i] += 1;
    int maxNum = -1;
    for (auto x: chart){
        if (x.first == x.second) maxNum = max(x.first, maxNum);
    }
    return maxNum;
}

int main()
{
    vector<int> arr{2,2,2,3,3};
    cout << luckyNum(arr) << endl;

    return 0;
}
